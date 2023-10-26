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

typedef struct Network_URI {

    System_String8 source;

    System_String8 queryString;

} * Network_URI;

void Network_URI_free(Network_URI that) {

}

typedef struct Network_HTTPRequest {
    struct System_Object base;

    Network_MessageHeader source;

    Network_HTTPMethod method;

    struct Network_URI uri;

    System_String8 version;

    System_String8Dictionary header;

} * Network_HTTPRequest;

void Network_HTTPRequest_free(Network_HTTPRequest that) {

}

struct System_Type Network_HTTPRequestType = {
    .base = { .type = typeof(System_Type) },
    .name = "HTTPRequest",
    .size = sizeof(struct Network_HTTPRequest),
};

Network_HTTPRequest HTTPRequest_parse(Network_MessageHeader message) { 
    Debug_assert(message);
    Debug_assert(message->contentCount);

    struct Network_HTTPRequest httpMessage; Stack_zero(httpMessage);
    System_String8 keys[64]; Stack_zero(keys);
    System_String8 values[64]; Stack_zero(values);
    struct System_String8Dictionary httpHeader; Stack_zero(httpHeader);
    httpHeader.capacity = 64;
    httpHeader.key = &keys;
    httpHeader.value = &values;

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
            System_SSize questionMark = System_String8_indexOf(string1, '?');
            if (questionMark > -1) {
                *(string1 + questionMark) = '\0';
                httpMessage.uri.queryString = string1 + questionMark + 1;
            }
            string1 += space + 1;

            if (!String8_equalsSubstring(string1, "HTTP/", 5)) {
                System_Console_writeLine("HTTPRequest_parse: No HTTP. {0:string} {1:string}", 2, string, httpMessage.uri.source);
                goto error;
            }
            string1 += 5;
            httpMessage.version = string1;

            if (httpMessage.uri.queryString)
                System_Console_writeLine("HTTPRequest_parse: {0:string} {1:string}?{2:string} HTTP/{3:string}", 4,
                    string, httpMessage.uri.source, httpMessage.uri.queryString, httpMessage.version);
            else
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
    httpMessage1->uri.queryString = httpMessage.uri.queryString;
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
    .base = { .type = typeof(System_Type) },
    .name = "HTTPResponse",
    .size = sizeof(struct Network_HTTPResponse),
};

typedef struct Network_MimeType {
    System_String8 extension;
    System_String8 name;
} * Network_MimeType;

struct Network_MimeType  Network_MimeTypes[] = {
    { "txt", "text/plain" },
    { "md", "text/markdown" },
    { "htm", "text/html" },
    { "html", "text/html" },
    { "xml", "text/xml" },
    { "css", "text/css" },
    { "csv", "text/csv" },
    { "rtf", "text/rtf" },
    { "js", "text/javascript" },
    { "ttf", "font/ttf" },
    { "otf", "font/otf" },
    { "gif", "image/gif" },
    { "tif", "image/tiff" },
    { "tiff", "image/tiff" },
    { "jpg", "image/jpeg" },
    { "jpeg", "image/jpeg" },
    { "png", "image/png" },
    { "bmp", "image/bmp" },
    { "svg", "image/svg+xml" },
    { "ico", "image/vnd.microsoft.icon" },
    { "bin", "application/octet-stream" },
    { "exe", "application/octet-stream" },
    { "iso", "application/x-iso9660-image" },
    { "json", "application/json" },
    { "sh", "application/x-sh" },
    { "ps", "application/postscript" },
    { "pdf", "application/pdf" },
    { "zip", "application/zip" },
    { "tar", "application/x-tar" },
    { "gz", "application/gzip" },
    { "7z", "application/x-7z-compressed" },
    { "xz", "application/x-xz" },
    { "deb", "application/x-deb" },
};

enum { Network_MimeTypes_Capacity = sizeof_array(Network_MimeTypes) };

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

    poller = base_Network_TCPSocket_poll(tcp, Network_PollFlags_IN);
    if (!(poller & Network_PollFlags_IN)) {
        System_Console_writeLine("HTTPService_serve: Error Poll IN {0:bool}", 1, (poller & Network_PollFlags_IN));  
        goto error;
    }

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

    for (System_Size i = 0; i < request->header->length; ++i)
        System_Console_writeLine("HTTPService_serve: {0:string}: {1:string}", 2, array(request->header->key)[i], array(request->header->value)[i]);

    System_Console_writeLine("HTTPService_serve: request->uri.source {0:string}", 1, request->uri.source);
    if (request->uri.queryString)
        System_Console_writeLine("HTTPService_serve: request->uri.queryString ?{0:string}", 1, request->uri.queryString);

    // Get a worker for the URI
    System_String8 currentDirectory = System_Directory_get_current();
    System_String8 requestPath = System_Path_combine(currentDirectory, request->uri.source);
    if (!String8_startsWith(requestPath, currentDirectory)) {
        System_Console_writeLine("HTTPService_serve: 500 Error {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
        goto continue_IN;
    }
    if (System_Directory_exists(requestPath)) {
        System_Console_writeLine("HTTPService_serve: Folder {0:string}", 1, requestPath);
        System_String8_replace(&requestPath, System_String8_concat(requestPath, "index.html"));
    }
    if (!System_File_exists(requestPath)) {
        System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
        goto continue_IN;
    }
    System_String8 requestExt = System_Path_getFileExtension(requestPath);
    System_Size mime = 0;
    for (; mime < Network_MimeTypes_Capacity; ++mime) {
        if (String8_equals(requestExt, Network_MimeTypes[mime].extension)) break;
    }
    if (mime == Network_MimeTypes_Capacity) {
        mime = 0;
        System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
        goto continue_IN;
    }
    System_Console_writeLine("HTTPService_serve: File {0:string}", 1, requestPath);
    struct System_File file; System_Stack_zero(file);
    if (!stack_System_File_open(&file, requestPath, System_File_Mode_readOnly)) {
        System_Console_writeLine("HTTPService_serve: File Error {0:string}", 1, requestPath);
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
    base_System_String8Dictionary_add(response->header, "Content-Length", System_UInt64_toString8base10(fileSize));
    base_System_String8Dictionary_add(response->header, "Content-Type", Network_MimeTypes[mime].name);

continue_IN:
    System_Memory_free(requestExt);
    System_Memory_free(requestPath);
    System_Memory_free(request->header);
    System_Memory_free(request);
    System_Memory_free(message->content);
    System_Memory_free(message);

    poller = base_Network_TCPSocket_poll(tcp, Network_PollFlags_OUT);
    if (!(poller & Network_PollFlags_OUT)) {
        System_Console_writeLine("HTTPService_serve: Error Poll OUT {0:bool}", 1, (poller & Network_PollFlags_OUT));  
        goto error;
    }
    if (!response) {
        System_Console_writeLine("HTTPService_serve: no response", 0);
        goto error;
    }
    if (!response->source) {
        response->source = System_Memory_allocClass(typeof(Network_MessageHeader));
        response->source->content = System_Memory_allocArray(typeof(Network_MessageBody), 2);
    }

    System_Char8  text1[System_String8_formatLimit_VALUE]; Stack_zero(text1);
    System_Size position = stack_System_String8_formatLine("HTTP/1.1 {0:uint} {1:string}\r", text1 + position, 2, response->status, Network_HTTPStatus_toString(response->status));
    for (System_Size i = 0; i < base_System_String8Dictionary_get_Length(response->header); ++i) {
        System_String8 key = base_System_String8Dictionary_get_index(response->header, i);
        System_String8 value = base_System_String8Dictionary_get_value(response->header, key);
        position += stack_System_String8_formatLine("{0:string}: {1:string}\r", text1 + position, 2, key, value);
    }
    position += stack_System_String8_formatLine("\r", text1 + position, 0);

    response->source->content[0].value = System_Memory_allocArray(typeof(System_Char8), position + 1);
    System_String8_copyTo(text1, response->source->content[0].value);
    response->source->content[0].length = position;
    ++response->source->contentCount;

    if (response->bufferLength) {
        response->source->content[1].value = response->buffer;
        response->source->content[1].length = response->bufferLength;
        ++response->source->contentCount;
    }
    if (response->source->contentCount == 2 && mime < Network_MimeTypes_Capacity && System_String8_startsWith("text/", Network_MimeTypes[mime].name))
        System_Console_writeLine("HTTPResponse_toMessage: {0:string}{1:string}", 2, response->source->content[0].value, response->source->content[1].value);
    else
        System_Console_writeLine("HTTPResponse_toMessage: {0:string}", 1, response->source->content[0].value);

    base_Network_TCPSocket_sendMessage(tcp, response->source, Network_MessageFlags_NOSIGNAL);

    System_Memory_free(response->buffer);
    System_Memory_free(response->source->content[0].value);
    System_Memory_free(response->source->content);
    System_Memory_free(response->source);
    System_Memory_free(response->header);
    System_Memory_free(response);

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

void System_Runtime_sigfault(System_Signal_Code code, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: code {1:uint32}, errno {2:uint32}, code1 {3:uint32}, sigfault.address {4:uint:hex}", 5,
        System_Signal_Code_toString(code), info->code, info->errno, info->code1, info->sigfault.address);
    System_Syscall_terminate(false);
}

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 1) {
        System_Console_writeLine__string("Usage: WebService <command> <file>");
        return false;
    }

    struct System_Signal signal; Stack_zero(signal);
    System_Signal_add(&signal, System_Signal_Code_SIGINT);
    System_Signal_add(&signal, System_Signal_Code_SIGILL);
    System_Signal_add(&signal, System_Signal_Code_SIGFPE);
    System_Signal_add(&signal, System_Signal_Code_SIGSEGV);
    System_Signal_unblock(&signal);
    System_Signal_handle(System_Signal_Code_SIGINT, System_Runtime_CTRLC);
    System_Signal_act(System_Signal_Code_SIGILL, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Code_SIGFPE, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Code_SIGSEGV, System_Runtime_sigfault);

    System_Directory_change("www");

    Network_TCPSocket tcp = new_Network_TCPSocket();
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_REUSEADDR, true);
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_REUSEPORT, true);

    Network_IP4Address ip4 = { .address32 = inline_System_UInt32_toNetworkOrder(0x7F000001) }; // { 127, 0, 0, 1 }
    System_UInt16 port = 8081;
    base_Network_TCPSocket_bind(tcp, ip4, port);
    System_Console_writeLine("WebService Network_IP4Address: {0:uint8}.{1:uint8}.{2:uint8}.{3:uint8}:{4:uint16}", 5, 
        ip4.address[0], ip4.address[1], ip4.address[2], ip4.address[3], port);

    base_Network_TCPSocket_listen(tcp, 512);

    while (true) {

        if (System_Runtime_HitCTRLC) break;
     
        Network_TCPSocket tcp1 = base_Network_TCPSocket_accept(tcp);
        if (!tcp1) continue;
        
        System_Thread thread1 = System_Thread_create(HTTPService_serve, 1, tcp1);
        if (!thread1) {
            base_Network_TCPSocket_close(tcp1);
            continue;
        }

        System_Thread_join(thread1);
    }
    return false;
}
