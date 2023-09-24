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

typedef struct Network_HTTPRequest {
    struct System_Object base;

    Network_MessageHeader source;

    Network_HTTPMethod method;

    struct Network_URI uri;

    System_String8 version;

    System_String8Dictionary header;

} * Network_HTTPRequest;

struct System_Type Network_HTTPRequestType = {
    .base = stack_System_Object(System_Type),
    .name = "HTTPRequest",
    .size = sizeof(struct Network_HTTPRequest),
};

Network_HTTPRequest HTTPRequest_parse(Network_MessageHeader message) { 
    Debug_assert(message);
    Debug_assert(message->contentCount);

    struct Network_HTTPRequest httpMessage = {
        .base = { .type = typeof(Network_HTTPRequest) },
        .method = 0,
    };
    System_String8 keys[64]; for (Size i = 0; i < 64; ++i) keys[i] = null;
    System_String8 values[64]; for (Size i = 0; i < 64; ++i) values[i] = null;
    struct System_String8Dictionary httpHeader = { 
        .base = { .type = typeof(System_String8Dictionary) },
        .capacity = 64,
        .key = &keys,
        .value = &values,
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

        System_SSize dot = System_String8_indexOf(string, ':');
        if (dot == -1) {
            System_Console_writeLine("HTTPRequest_parse: No Header Name", 0);
            goto error;
        }
        *(string + dot) = '\0';
        if (*(string + dot + 1) == ' ') { *(string + dot + 1) = '\0'; ++dot; }

        base_System_String8Dictionary_add(&httpHeader, string, string + dot + 1);

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
    Network_HTTPRequest httpMessage1 = System_Memory_allocClass(typeof(Network_HTTPRequest));
    httpMessage1->method = httpMessage.method;
    httpMessage1->uri.source = httpMessage.uri.source;
    httpMessage1->version = httpMessage.version;
    httpMessage1->header = System_Memory_allocClass(typeof(System_String8Dictionary));
    base_System_String8Dictionary_init(httpMessage1->header, 64);
    System_Memory_copyTo(httpHeader.key, 64 * sizeof(System_String8), httpMessage1->header->key);
    System_Memory_copyTo(httpHeader.value, 64 * sizeof(System_String8), httpMessage1->header->value);
    httpMessage1->header->length = httpHeader.length;
    httpMessage1->source = System_Memory_addReference(message);
    return httpMessage1;
error:
    return null;
}

typedef struct Network_HTTPResponse {
    struct System_Object base;

    Network_MessageHeader source;

    Network_HTTPStatus status;

    System_String8Dictionary header;

    System_Size bufferLength;

    System_String8 buffer;

} * Network_HTTPResponse;

struct System_Type Network_HTTPResponseType = {
    .base = stack_System_Object(System_Type),
    .name = "HTTPResponse",
    .size = sizeof(struct Network_HTTPResponse),
};

Network_HTTPResponse Network_HTTPResponse_create(Network_HTTPStatus status) {

    Network_HTTPResponse response = System_Memory_allocClass(typeof(Network_HTTPResponse));

    response->header = System_Memory_allocClass(typeof(System_String8Dictionary));
    base_System_String8Dictionary_init(response->header, 64);

    response->status = status;
    return response;
}

String8 Network_HTTPStatus_toString(Network_HTTPStatus value) {
    switch (value) {
    case Network_HTTPStatus_OK: return "OK";
    case Network_HTTPStatus_FileNotFound: return "FileNotFound";
    case Network_HTTPStatus_Error: return "Error";
    }
    return "UNKNOWN";
}

IntPtr HTTPService_serve(Size argc, Var argv[]) {
    if (argc < 1) {
        System_Console_writeLine("HTTPService_serve: No TCPSocket", 0);
        return false;
    }
    Network_TCPSocket tcp = argv[0];

    struct { int on; int seconds; } linger = { 1, 0 };
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_LINGER, (System_IntPtr)&linger);

    Network_PollFlags poller = 0;
    Network_MessageHeader message = null;
    Network_HTTPRequest request = null;
    Network_HTTPResponse response = null;
    System_Size i;

    while (1) {

        poller = base_Network_TCPSocket_poll(tcp, Network_PollFlags_IN | Network_PollFlags_URGENT |  Network_PollFlags_OUT | Network_PollFlags_ERROR | Network_PollFlags_HANGUP | Network_PollFlags_INVALID);

        System_Console_writeLine("HTTPService_serve: Poll IN {0:bool}, URGENT {1:bool}, OUT {2:bool}, ERROR {3:bool}, HANGUP {4:bool}, INVALID {5:bool}", 6, 
            (poller & Network_PollFlags_IN), (poller & Network_PollFlags_URGENT), (poller & Network_PollFlags_OUT), (poller & Network_PollFlags_ERROR),
            (poller & Network_PollFlags_HANGUP), (poller & Network_PollFlags_INVALID));  

        if (poller & Network_PollFlags_IN) {
            message = base_Network_TCPSocket_receiveMessage(tcp, 0);
            if (!message) {
                System_Console_writeLine("HTTPService_serve: No Message", 0);
                goto error;
            }
            System_Console_writeLine("HTTPService_serve: MessageHeader contentCount {0:uint}, content[0] length {1:uint}", 2,
                message->contentCount, (!message->contentCount ? 0 : message->content[0].length));

            /*
                // TODO: reallocArray, if 0 == message->contentCount % Network_MessageHeader_ContentCapacity
                i = request->source->contentCount++;
                request->source->content[i].value = message->content[0].value;
                request->source->content[i].length = message->content[0].length;
                System_Memory_free(message->content);
                System_Memory_free(message);
                continue;
            }*/

            request = HTTPRequest_parse(message);
            if (!request) {
                System_Console_writeLine("HTTPService_serve: request not parsed", 0);
                System_Memory_free(message->content);
                System_Memory_free(message);
                goto error;
            }

            for (Size i = 0; i < request->header->length; ++i)
                System_Console_writeLine("HTTPService_serve: {0:string}: {1:string}", 2, array(request->header->key)[i], array(request->header->value)[i]);

            System_Console_writeLine("HTTPService_serve: request->uri.source {0:string}", 1, request->uri.source);

            // Get a worker for the URI
            String8 currentDirectory = System_Directory_get_current();
            String8 requestPath = System_Path_combine(currentDirectory, request->uri.source);
            if (!String8_startsWith(requestPath, currentDirectory)) {
                System_Console_writeLine("HTTPService_serve: 500 Error {0:string}", 1, requestPath);
                response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
                goto continue_IN;
            }
            if (System_Directory_exists(requestPath)) {
                System_Console_writeLine("HTTPService_serve: Folder {0:string}", 1, requestPath);
                String8 new_requestPath = System_String8_concat(requestPath, "index.html");
                System_Memory_free(requestPath);
                requestPath = new_requestPath;
            }
            if (!System_File_exists(requestPath)) {
                System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
                response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
            }
            else {
                System_Console_writeLine("HTTPService_serve: File {0:string}", 1, requestPath);

                struct System_File file = stack_System_File();
                if (!stack_System_File_open(&file, requestPath, System_File_Mode_readOnly)) {
                    System_Console_writeLine("HTTPService_serve: No File {0:string}", 1, requestPath);
                    response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
                    goto continue_IN;
                }
                System_Size fileSize = base_System_File_get_Length(&file);
                System_String8 text = System_Memory_allocArray(typeof(System_Char8), fileSize + 1);
                base_System_File_read(&file, text, fileSize);
                base_System_File_close(&file);

                response = Network_HTTPResponse_create(Network_HTTPStatus_OK);
                response->buffer = text;
                response->bufferLength = fileSize;
                String8 scratch = System_Memory_allocArray(typeof(System_Char8), System_UInt64_String8base10Length_DEFAULT);
                stack_UInt64_toString8base10(fileSize, scratch);
                base_System_String8Dictionary_add(response->header, "Content-Length", scratch);
                base_System_String8Dictionary_add(response->header, "Content-Type", "text/plain");
            }

continue_IN:
            System_Memory_free(requestPath);
            System_Memory_free(request);
            System_Memory_free(message->content);
            System_Memory_free(message);
            continue;
        }
        if (poller & Network_PollFlags_OUT) {
            if (!response) {
                System_Console_writeLine("HTTPService_serve: no response", 0);
                continue;
            }

            Char8  text1[System_String8_formatLimit_VALUE]; for (Size i = 0; i < System_String8_formatLimit_VALUE; ++i) text1[i] = 0;
            Size position = 0;
            position += stack_System_String8_formatLine("HTTP/1.1 {0:uint} {1:string}\r", text1 + position, 2, response->status, Network_HTTPStatus_toString(response->status));

            for (Size i = 0; i < base_System_String8Dictionary_get_Length(response->header); ++i) {
                String8 key = base_System_String8Dictionary_get_index(response->header, i);
                String8 value = base_System_String8Dictionary_get_value(response->header, key);
                position += stack_System_String8_formatLine("{0:string}: {1:string}\r", text1 + position, 2, key, value);
            }

            position += stack_System_String8_formatLine("\r", text1 + position, 0);

            if (!response->source) {
                response->source = System_Memory_allocClass(typeof(Network_MessageHeader));
                response->source->content = System_Memory_allocArray(typeof(Network_MessageBody), 2);
            }

            response->source->content[0].value = System_Memory_allocArray(typeof(System_Char8), position + 1);
            System_String8_copyTo(text1, response->source->content[0].value);
            response->source->content[0].length = position;
            ++response->source->contentCount;

            if (response->bufferLength) {
                response->source->content[1].value = response->buffer;
                response->source->content[1].length = response->bufferLength;
                ++response->source->contentCount;
                System_Console_writeLine("HTTPResponse_toMessage: {0:string}{1:string}", 2, response->source->content[0].value, response->source->content[1].value);
            }
            else
                System_Console_writeLine("HTTPResponse_toMessage: {0:string}", 1, response->source->content[0].value);

            base_Network_TCPSocket_sendMessage(tcp, response->source, Network_MessageFlags_NOSIGNAL);

            System_Memory_free(response->source->content[0].value);
            System_Memory_free(response->source->content);
            System_Memory_free(response->source);
            System_Memory_free(response);
        }
        break;
    }
    base_Network_TCPSocket_close(tcp);
    return true;
error:
    base_Network_TCPSocket_close(tcp);
    return false;
}

Bool System_Runtime_HitCTRLC = false;

void System_Runtime_CTRLC(System_Signal_Code code) {
    System_Runtime_HitCTRLC = true;
}

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 1) {
        System_Console_writeLine__string("Usage: WebService <command> <file>");
        return false;
    }

    /*struct System_Signal_Set procmask; Stack_free(procmask);
    procmask.signal[0] |= (1 << (System_Signal_Code_SIGINT - 1));
    System_Signal_unblock(&procmask);
    System_Signal_signal(System_Signal_Code_SIGINT, System_Runtime_CTRLC);*/

    System_Directory_change("www");

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

        if (System_Runtime_HitCTRLC) System_Console_exit(false);
    }
    return false;
}
