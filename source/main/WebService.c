/* Gemeinfrei. Public Domain. */
#include "../System.internal.h"
#include <min/System.h>

typedef System_IntPtr Network_HTTPMethod;
enum {
    Network_HTTPMethod_GET = 1,
    Network_HTTPMethod_HEAD,
    Network_HTTPMethod_POST,
    Network_HTTPMethod_PUT,
    Network_HTTPMethod_OPTIONS,
    Network_HTTPMethod_DELETE,
};

typedef System_String8 Network_URISchema;
#define Network_URISchema_http "http"

typedef struct Network_URI {

    System_String8 source;

} * Network_URI;

typedef struct Network_HTTPMessage {
    struct System_Object base;

    Network_MessageHeader source;

    Network_HTTPMethod method;

    struct Network_URI uri;

    System_String8 version;

    System_VarDictionary header;

} * Network_HTTPMessage;

struct System_Type Network_HTTPMessageType = {
    .base = stack_System_Object(System_Type),
    .name = "HTTPMessage",
    .size = sizeof(struct Network_HTTPMessage),
};

Network_HTTPMessage HTTPRequest_parse(Network_MessageHeader message) { 
    Debug_assert(message);
    Debug_assert(message->contentCount);

    struct Network_HTTPMessage httpMessage = {
        .base = { .type = typeof(Network_HTTPMessage) },
        .method = 0,
    };
    System_String8 keys[64]; for (Size i = 0; i < 64; ++i) keys[i] = null;
    System_String8 values[64]; for (Size i = 0; i < 64; ++i) values[i] = null;
    struct System_VarDictionary httpHeader = { 
        .base = { .type = typeof(System_VarDictionary) },
        .capacity = 64,
        .key = (Var(*)[])&keys,
        .value = (Var(*)[])&values,
    };

    System_String8 string = message->content[0].value;
    System_Size remainSize = message->content[0].length;
    while (1) {

        System_SSize linefeed = System_String8_indexOf__size(string, '\n', remainSize);
        remainSize -= linefeed + 1;
        if (linefeed == -1) {
            System_Console_writeLine("HTTPRequest_parse: No linefeed", 0);
            goto error;
        }
        *(string + linefeed) = '\0';
        if (linefeed > 0)
            if (*(string + linefeed - 1) == '\r')
                *(string + linefeed - 1) = '\0';
        if (linefeed < 2) {
            System_Console_writeLine("HTTPRequest_parse: End of Header", 0);
            goto body;
        }
        System_SSize nullchar = System_String8_indexOf(string, '\0');
        if (nullchar > -1) {
            System_Console_writeLine("HTTPRequest_parse: null in there", 0);
            goto error;
        }

        if (!httpMessage.method) {
            System_String8 string1 = string;

            if (String8_equalsSubstring(string, "GET", 3)) { httpMessage.method = Network_HTTPMethod_GET; string1 += 3; }
            else if (String8_equalsSubstring(string, "HEAD", 4)) { httpMessage.method = Network_HTTPMethod_HEAD; string1 += 4; }
            else if (String8_equalsSubstring(string, "POST", 4)) { httpMessage.method = Network_HTTPMethod_POST; string1 += 4; }
            else if (String8_equalsSubstring(string, "PUT", 3)) { httpMessage.method = Network_HTTPMethod_PUT; string1 += 3; }
            else if (String8_equalsSubstring(string, "OPTIONS", 7)) { httpMessage.method = Network_HTTPMethod_OPTIONS; string1 += 7; }
            else if (String8_equalsSubstring(string, "DELETE", 6)) { httpMessage.method = Network_HTTPMethod_DELETE; string1 += 6; }
            if (!httpMessage.method) {
                System_Console_writeLine("HTTPRequest_parse: No Method", 0);
                goto error;
            }
            *(string1++) = '\0';

            System_SSize space = System_String8_indexOf(string1, ' ');
            if (space == -1) {
                System_Console_writeLine("HTTPRequest_parse: No Space after URI. {0:string}", 1, string);
                goto error;
            }
            *(string1 + space) = '\0';
            httpMessage.uri.source = string1;
            string1 += space + 1;

            if (!String8_equalsSubstring(string1, "HTTP/", 5)) {
                System_Console_writeLine("HTTPRequest_parse: No HTTP. {0:string} {1:string}", 2, string, httpMessage.uri.source);
                goto error;
            }
            string1 += 5;
            httpMessage.version = string1;

            System_Console_writeLine("HTTPRequest_parse: {0:string} {1:string} HTTP/{2:string}", 3,
                string, httpMessage.uri.source, httpMessage.version);

            goto nextHeader;
        }

        System_SSize ddot = System_String8_indexOf(string, ':');
        if (ddot == -1) {
            System_Console_writeLine("HTTPRequest_parse: No Header Name", 0);
            goto error;
        }
        *(string + ddot) = '\0';
        if (*(string + ddot + 1) == ' ') { *(string + ddot + 1) = '\0'; ++ddot; }

        base_System_VarDictionary_add(&httpHeader, string, string + ddot + 1);

nextHeader:
        string += linefeed + 1;
    }
body:
    if (remainSize) {
        if (1 == message->contentCount) {
            System_Console_writeLine("HTTPRequest_parse: Header, remainSize, but no next message", 0);
            String8 newBody = System_Memory_allocArray(typeof(System_Char8), remainSize);
            message->content[1].value = newBody;
            message->content[1].length = remainSize;
            message->contentCount = 2;
        } else {
            System_Console_writeLine("HTTPRequest_parse: Header, remainSize", 0);
            String8 newBody = System_String8_concat(string, message->content[1].value);
            System_Memory_free(message->content[1].value);
            message->content[1].value = newBody;
            message->content[1].length += remainSize;
        }
    }
    Network_HTTPMessage httpMessage1 = System_Memory_allocClass(typeof(Network_HTTPMessage));
    httpMessage1->method = httpMessage.method;
    httpMessage1->uri.source = httpMessage.uri.source;
    httpMessage1->version = httpMessage.version;
    httpMessage1->header = System_Memory_allocClass(typeof(System_VarDictionary));
    base_System_VarDictionary_init(httpMessage1->header, 64);
    System_Memory_copyTo(httpHeader.key, 64, httpMessage1->header->key);
    System_Memory_copyTo(httpHeader.value, 64, httpMessage1->header->value);
    httpMessage1->header->length = httpHeader.length;
    httpMessage1->source = System_Memory_addReference(message);
    return httpMessage1;
error:
    return null;
}

IntPtr HTTPService_serve(Size argc, Var argv[]) {
    if (argc < 1) return false;
    Network_TCPSocket tcp = argv[0];
    Network_PollFlags poller = 0;
    Network_MessageHeader messageIn = null, messageOut = null;
    Network_HTTPMessage request = null, response = null;
    System_Size i;

    while (1) {

        poller = base_Network_TCPSocket_poll(tcp, Network_PollFlags_IN | Network_PollFlags_URGENT |  Network_PollFlags_OUT | Network_PollFlags_ERROR | Network_PollFlags_HANGUP | Network_PollFlags_INVALID);

        System_Console_writeLine("HTTPService_serve: Poll IN {0:bool}, URGENT {1:bool}, OUT {2:bool}, ERROR {3:bool}, HANGUP {4:bool}, INVALID {5:bool}", 6, 
            (poller & Network_PollFlags_IN), (poller & Network_PollFlags_URGENT), (poller & Network_PollFlags_OUT), (poller & Network_PollFlags_ERROR),
            (poller & Network_PollFlags_HANGUP), (poller & Network_PollFlags_INVALID));  

        if (poller & Network_PollFlags_IN) {
            messageIn = base_Network_TCPSocket_receiveMessage(tcp, 0);
            if (!messageIn) {
                System_Console_writeLine("HTTPService_serve: No Message", 0);
                return false;
            }
            System_Console_writeLine("HTTPService_serve: MessageHeader contentCount {0:uint}, content[0] length {1:uint}", 2,
                messageIn->contentCount, (!messageIn->contentCount ? 0 : messageIn->content[0].length));

            if (request) {
                // TODO: reallocArray, if 0 == messageIn->contentCount % Network_MessageHeader_ContentCapacity
                i = request->source->contentCount++;
                request->source->content[i].value = messageIn->content[0].value;
                request->source->content[i].length = messageIn->content[0].length;
                System_Memory_free(messageIn->content);
                System_Memory_free(messageIn);
                continue;
            }

            request = HTTPRequest_parse(messageIn);
            if (!request) {
                System_Memory_free(messageIn->content);
                System_Memory_free(messageIn);
                return false;
            }

            for (Size i = 0; i < request->header->length; ++i)
                System_Console_writeLine("HTTPService_serve: {0:string}: {1:string}", 2, array(request->header->key)[i], array(request->header->value)[i]);

            // Get a worker for the URI
            String8 cwd = base_System_String8Dictionary_get_value(System_Environment_Arguments, "PWD");
            String8 requestPath = System_Path_combine(cwd ? cwd : ".", request->uri.source);

            System_Console_writeLine("HTTPService_serve: {0:string}", 1, requestPath);
            // Try if directory


            System_Memory_free(messageIn->content);
            System_Memory_free(messageIn);
            continue;
        }
        if (poller & Network_PollFlags_OUT) {
            //base_Network_TCPSocket_sendMessage(tcp, returnMessage, 0);
        }
        break;
    }

    return true;
}

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 1) {
        System_Console_writeLine__string("Usage: WebService <command> <file>");
        return false;
    }

    Network_TCPSocket tcp = Network_TCPSocket_create();
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_REUSEADDR, true);
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_REUSEPORT, true);

    Network_IP4Address ip4 = { .address32 = inline_System_UInt32_toNetworkOrder(0x7F000001) }; // { 127, 0, 0, 1 }
    System_UInt16 port = 8081;
    base_Network_TCPSocket_bind(tcp, ip4, port);
    System_Console_writeLine("WebService Network_IP4Address: {0:uint8}.{1:uint8}.{2:uint8}.{3:uint8}:{4:uint16}", 5, 
        ip4.address[0], ip4.address[1], ip4.address[2], ip4.address[3], port);

    base_Network_TCPSocket_listen(tcp, 512);


    while (true) {
     
        Network_TCPSocket tcp1 = base_Network_TCPSocket_accept(tcp);
        
        System_Thread thread1 = System_Thread_create(HTTPService_serve, 1, tcp1);

        System_Thread_join(thread1);

    }
    return false;
}
