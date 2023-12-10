/* Gemeinfrei. Public Domain. */
#include "../System.internal.h"
#include <min/System.h>

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
    { "ico", "image/x-icon" },
    { "svg", "image/svg+xml" },
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

const System_Size Network_MimeTypes_Capacity = sizeof_array(Network_MimeTypes);

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
    if (that->source) System_Memory_free(that->source);
}

typedef struct Network_HTTPRequest {
    struct System_Object base;

    Network_HTTPMethod method;

    struct Network_URI uri;

    System_String8 version;

    System_String8Dictionary header;

} * Network_HTTPRequest;

void base_Network_HTTPRequest_free(Network_HTTPRequest that) {
    Network_URI_free(&that->uri);
    if (that->version) System_Memory_free(that->version);
    if (that->header) System_Memory_free(that->header);
}

struct System_Type_FunctionInfo Network_HTTPRequestTypeFunctions[] = {
    { .function = base_System_Object_free, .value = base_Network_HTTPRequest_free },
};

struct System_Type Network_HTTPRequestType = {
    .base = { .type = typeof(System_Type) },
    .name = "HTTPRequest",
    .size = sizeof(struct Network_HTTPRequest),
    .baseType = &System_ObjectType,
    .functions = { .length = sizeof_array(Network_HTTPRequestTypeFunctions), .value = &Network_HTTPRequestTypeFunctions, },
};

Network_HTTPRequest HTTPRequest_parse(System_String message) {
    Debug_assert(message);
    Debug_assert(message->length);

    struct Network_HTTPRequest httpRequest; Stack_clear(httpRequest);
    System_String8 keys[64]; Stack_clear(keys);
    System_String8 values[64]; Stack_clear(values);
    struct System_String8Dictionary httpHeader; Stack_clear(httpHeader);
    httpHeader.capacity = 64;
    httpHeader.key = &keys;
    httpHeader.value = &values;

    System_String8 string = message->value;
    System_Size remainSize = message->length;
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

        if (!httpRequest.method) {
            System_String8 string1 = string;

            if (String8_equalsSubstring(string, "GET", 3)) { httpRequest.method = Network_HTTPMethod_GET; string1 += 3; }
            else if (String8_equalsSubstring(string, "HEAD", 4)) { httpRequest.method = Network_HTTPMethod_HEAD; string1 += 4; }
            else if (String8_equalsSubstring(string, "POST", 4)) { httpRequest.method = Network_HTTPMethod_POST; string1 += 4; }
            else if (String8_equalsSubstring(string, "PUT", 3)) { httpRequest.method = Network_HTTPMethod_PUT; string1 += 3; }
            else if (String8_equalsSubstring(string, "OPTIONS", 7)) { httpRequest.method = Network_HTTPMethod_OPTIONS; string1 += 7; }
            else if (String8_equalsSubstring(string, "DELETE", 6)) { httpRequest.method = Network_HTTPMethod_DELETE; string1 += 6; }
            if (!httpRequest.method) {
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
            httpRequest.uri.source = System_String8_copy(string1);
            System_SSize questionMark = System_String8_indexOf(httpRequest.uri.source, '?');
            if (questionMark > -1) {
                *(httpRequest.uri.source + questionMark) = '\0';
                httpRequest.uri.queryString = httpRequest.uri.source + questionMark + 1;
            }
            string1 += space + 1;

            if (!String8_equalsSubstring(string1, "HTTP/", 5)) {
                System_Console_writeLine("HTTPRequest_parse: No HTTP. {0:string} {1:string}", 2, string, httpRequest.uri.source);
                goto error;
            }
            string1 += 5;
            httpRequest.version = System_String8_copy(string1);

            if (httpRequest.uri.queryString)
                System_Console_writeLine("HTTPRequest_parse: {0:string} {1:string}?{2:string} HTTP/{3:string}", 4,
                    string, httpRequest.uri.source, httpRequest.uri.queryString, httpRequest.version);
            else
                System_Console_writeLine("HTTPRequest_parse: {0:string} {1:string} HTTP/{2:string}", 3,
                    string, httpRequest.uri.source, httpRequest.version);

            goto nextHeader;
        }

        System_SSize dot = System_String8_indexOf(string, ':');
        if (dot == -1) {
            System_Console_writeLine("HTTPRequest_parse: No Header Name", 0);
            goto error;
        }
        *(string + dot) = '\0';
        if (*(string + dot + 1) == ' ') { *(string + dot + 1) = '\0'; ++dot; }

        base_System_String8Dictionary_add(&httpHeader, System_String8_copy(string), System_String8_copy(string + dot + 1));

nextHeader:
        string += linefeed + 1;
    }
body:
    Network_HTTPRequest httpRequest1 = System_Memory_allocClass(typeof(Network_HTTPRequest));
    httpRequest1->method = httpRequest.method;
    httpRequest1->uri.source = httpRequest.uri.source;
    httpRequest1->uri.queryString = httpRequest.uri.queryString;
    httpRequest1->version = httpRequest.version;
    httpRequest1->header = System_Memory_allocClass(typeof(System_String8Dictionary));
    base_System_String8Dictionary_init(httpRequest1->header, 64);
    System_Memory_copyTo(httpHeader.key, 64 * sizeof(System_String8), httpRequest1->header->key);
    System_Memory_copyTo(httpHeader.value, 64 * sizeof(System_String8), httpRequest1->header->value);
    httpRequest1->header->length = httpHeader.length;
    return httpRequest1;
error:
    return null;
}

typedef struct Network_HTTPResponse {
    struct System_Object base;

    struct System_String source;

    Network_HTTPStatus status;

    System_String8Dictionary header;

    /* System_Bool keepAlive; */

    struct System_String buffer;

} * Network_HTTPResponse;

void base_Network_HTTPResponse_free(Network_HTTPResponse that) {
    if (that->header) System_Memory_free(that->header);
    System_Memory_freeStruct(&that->source, typeof(System_String));
    System_Memory_freeStruct(&that->buffer, typeof(System_String));
}

struct System_Type_FunctionInfo Network_HTTPResponseTypeFunctions[] = {
    { .function = base_System_Object_free, .value = base_Network_HTTPResponse_free },
};

struct System_Type Network_HTTPResponseType = {
    .base = { .type = typeof(System_Type) },
    .name = "HTTPResponse",
    .size = sizeof(struct Network_HTTPResponse),
    .baseType = &System_ObjectType,
    .functions = { .length = sizeof_array(Network_HTTPResponseTypeFunctions), .value = &Network_HTTPResponseTypeFunctions, },
};

Network_HTTPResponse Network_HTTPResponse_create(Network_HTTPStatus status) {

    Network_HTTPResponse response = System_Memory_allocClass(typeof(Network_HTTPResponse));

    response->header = System_Memory_allocClass(typeof(System_String8Dictionary));
    base_System_String8Dictionary_init(response->header, 64);

    response->status = status;
    return response;
}

System_String8 Network_HTTPStatus_toString(Network_HTTPStatus value) {
    switch (value) {
    case Network_HTTPStatus_OK: return "OK";
    case Network_HTTPStatus_FileNotFound: return "FileNotFound";
    case Network_HTTPStatus_Error: return "Error";
    default: return "UNKNOWN";
    }
}

Network_HTTPResponse HTTPService_serve(Network_HTTPRequest request) {
    Network_HTTPResponse response = null;

    for (System_Size i = 0; i < request->header->length; ++i) {
        System_String8 key = array(request->header->key)[i];
        System_String8 value = array(request->header->value)[i];
        System_Console_writeLine("HTTPService_serve: {0:string}: {1:string}", 2, key, value);
        // if (String8_equals(key, "Connection") && String8_equals(value, "keep-alive")) keepAlive = true;
    }

    System_Console_writeLine("HTTPService_serve: request->uri.source {0:string}", 1, request->uri.source);
    if (request->uri.queryString)
        System_Console_writeLine("HTTPService_serve: request->uri.queryString ?{0:string}", 1, request->uri.queryString);

    // Get a worker for the URI
    System_String8 currentDirectory = System_Directory_get_current();
    System_String8 requestPath = System_Path_combine(currentDirectory, request->uri.source);
    System_String8 requestExt = null;
    if (!String8_startsWith(requestPath, currentDirectory)) {
        System_Console_writeLine("HTTPService_serve: 500 Error {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
        goto respond;
    }
    if (System_Directory_exists(requestPath)) {
        System_Console_writeLine("HTTPService_serve: Folder {0:string}", 1, requestPath);
        System_String8_exchange(&requestPath, System_String8_concat(requestPath, "index.html"));
    }
    if (!System_File_exists(requestPath)) {
        System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
        goto respond;
    }
    requestExt = System_Path_getFileExtension(requestPath);
    System_Size mime = 0;
    for (; mime < Network_MimeTypes_Capacity; ++mime) {
        if (String8_equals(requestExt, Network_MimeTypes[mime].extension)) break;
    }
    if (mime == Network_MimeTypes_Capacity) {
        mime = 0;
        System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
        goto respond;
    }
    System_Console_writeLine("HTTPService_serve: File {0:string}", 1, requestPath);
    struct System_File file; System_Stack_clear(file);
    if (!stack_System_File_open(&file, requestPath, System_File_Mode_readOnly)) {
        System_Console_writeLine("HTTPService_serve: File Error {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
        goto respond;
    }

    response = Network_HTTPResponse_create(Network_HTTPStatus_OK);

    System_Size fileSize = base_System_File_get_Length(&file);
    if (fileSize) {
        response->buffer.length = fileSize;
        response->buffer.value = System_Memory_allocArray(typeof(System_Char8), fileSize + 1);
        base_System_File_read(&file, response->buffer.value, fileSize);
    }
    base_System_File_close(&file);

    base_System_String8Dictionary_add(response->header, "Content-Length", System_UInt64_toString8base10(fileSize));
    base_System_String8Dictionary_add(response->header, "Content-Type", Network_MimeTypes[mime].name);
    base_System_String8Dictionary_add(response->header, "Connection", "close");

respond:
    if (currentDirectory) System_Memory_free(currentDirectory);
    if (requestExt) System_Memory_free(requestExt);
    if (requestPath) System_Memory_free(requestPath);
    //if (request) System_Memory_free(request);

    System_Char8  text1[System_String8_formatLimit_VALUE]; Stack_clear(text1);
    System_Size position = stack_System_String8_formatLine("HTTP/1.1 {0:uint} {1:string}\r", text1 + position, 2, response->status, Network_HTTPStatus_toString(response->status));
    for (System_Size i = 0; i < base_System_String8Dictionary_get_Length(response->header); ++i) {
        System_String8 key = base_System_String8Dictionary_get_index(response->header, i);
        System_String8 value = base_System_String8Dictionary_get_value(response->header, key);
        position += stack_System_String8_formatLine("{0:string}: {1:string}\r", text1 + position, 2, key, value);
    }
    position += stack_System_String8_formatLine("\r", text1 + position, 0);

    response->source.length = position;
    response->source.value = System_Memory_allocArray(typeof(System_Char8), position + 1);
    System_String8_copyTo(text1, response->source.value);

    if (response->buffer.length && System_String8_startsWith(Network_MimeTypes[mime].name, "text/"))
        System_Console_writeLine("HTTPResponse_toMessage: {0:string}{1:string}", 2, response->source.value, response->buffer.value);
    else
        System_Console_writeLine("HTTPResponse_toMessage: {0:string}", 1, response->source.value);

    return response;
}

__volatile__ System_Bool System_Runtime_HitCTRLC = false;

void System_Runtime_CTRLC(System_Signal_Number number) {
    System_Runtime_HitCTRLC = true;
}

void System_Runtime_sigfault(System_Signal_Number number, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: number {1:uint32}, errno {2:uint32}, code {3:uint32}, sigfault.address {4:uint:hex}", 5,
        System_Signal_Number_toString(number), info->number, info->errno, info->code, info->sigfault.address);
    System_Syscall_terminate(false);
}

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 1) {
        System_Console_writeLine__string("Usage: WebService <command> <file>");
        return false;
    }

    struct System_Signal signal; System_Stack_clear(signal);
    System_Signal_add(&signal, System_Signal_Number_SIGINT);
    System_Signal_add(&signal, System_Signal_Number_SIGILL);
    System_Signal_add(&signal, System_Signal_Number_SIGFPE);
    System_Signal_add(&signal, System_Signal_Number_SIGSEGV);
    System_Signal_unblock(&signal);
    System_Signal_handle__flags(System_Signal_Number_SIGINT, System_Runtime_CTRLC, 0/*System_Signal_Flags_RESTART*/);
    System_Signal_act__flags(System_Signal_Number_SIGILL, System_Runtime_sigfault, 0/*System_Signal_Flags_RESTART*/);
    System_Signal_act__flags(System_Signal_Number_SIGFPE, System_Runtime_sigfault, 0/*System_Signal_Flags_RESTART*/);
    System_Signal_act__flags(System_Signal_Number_SIGSEGV, System_Runtime_sigfault, 0/*System_Signal_Flags_RESTART*/);

    System_Directory_change("www");

    Network_TCPSocket sockets[64]; Stack_clear(sockets); System_Size socketC = 1;
    Network_PollFlags polls[64]; Stack_clear(polls);
    Network_HTTPResponse responses[64]; Stack_clear(responses);

    sockets[0] = new_Network_TCPSocket__flags(Network_SocketType_NONBLOCK | Network_SocketType_CLOSEONEXEC);

    /*System_IntPtr socket0_status_flags =  System_Syscall_fcntl(sockets[0]->socketId, System_File_ControlCommand_GetFileStatusFlags);
    System_Syscall_fcntl1(sockets[0]->socketId, System_File_ControlCommand_SetFileStatusFlags, socket0_status_flags | Network_SocketType_NONBLOCK);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Syscall_fcntl Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));

    System_IntPtr socket0_descriptor_flags =  System_Syscall_fcntl(sockets[0]->socketId, System_File_ControlCommand_GetFileDescriptorFlags);
    System_Syscall_fcntl1(sockets[0]->socketId, System_File_ControlCommand_SetFileDescriptorFlags, socket0_descriptor_flags | Network_SocketType_CLOSEONEXEC);
    errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Syscall_fcntl Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno)); */

    Network_TCPSocket_setSocketOption(sockets[0], Network_SocketOption_REUSEADDR, true);
    Network_TCPSocket_setSocketOption(sockets[0], Network_SocketOption_REUSEPORT, true);

    Network_IP4Address ip4 = { .address32 = inline_System_UInt32_toNetworkOrder(0x7F000001) }; // { 127, 0, 0, 1 }
    System_UInt16 port = 8082;
    Network_TCPSocket_bind(sockets[0], ip4, port);

    System_Console_writeLine("WebService Network_IP4Address: {0:uint8}.{1:uint8}.{2:uint8}.{3:uint8}:{4:uint16}", 5,
        ip4.address[0], ip4.address[1], ip4.address[2], ip4.address[3], port);
    Network_TCPSocket_listen(sockets[0], 64);

    while (true) {

        if (System_Runtime_HitCTRLC) break;

        System_Size active = Network_TCPSocket_pollAny(sockets, socketC, Network_PollFlags_IN, polls);
        for (System_Size i = 0; i < socketC; ++i) {
            if (polls[i] & Network_PollFlags_ERROR) {
                System_Console_writeLine("HTTPService_serve: POLLIN: POLLERR", 0);
                continue;
            }
            if (!(polls[i] & Network_PollFlags_IN)) continue;
            if (i == 0) {
                if (socketC == 64) {
                    System_Console_writeLine("HTTPService_serve: NO MORE ACCEPTs", 0);
                    continue;
                }
                Network_TCPSocket incoming[8]; System_Stack_clear(incoming);
                for (System_Size n = 0; n < 8; ++n) 
                    incoming[n] = Network_TCPSocket_accept__flags(sockets[0], Network_SocketType_NONBLOCK | Network_SocketType_CLOSEONEXEC);
                for (System_Size n = 0; n < 8; ++n) {
                    if (incoming[n]) {
                        Network_TCPSocket_setSocketOption(incoming[n], Network_SocketOption_LINGER, 1UL << 32);

                        System_Console_writeLine("HTTPService_serve: ACCEPT: socket {0:uint}", 1, socketC);
                        sockets[socketC++] = incoming[n];
                    }
                }
                continue;
            }
            if (!sockets[i]) continue;

            System_Console_writeLine("HTTPService_serve: socket {0:uint}: receiving message", 1, i);
            System_String message = Network_TCPSocket_receive__flags(sockets[i], 0);
            if (!message) {
                System_Console_writeLine("HTTPService_serve: No Message", 0);
                Network_TCPSocket_close(sockets[i]);
                continue;
            }
            Network_HTTPRequest request = HTTPRequest_parse(message);
            System_Memory_free(message);
            if (!request) {
                System_Console_writeLine("HTTPService_serve: Message not parsed", 0);
                Network_TCPSocket_close(sockets[i]);
                continue;
            }
            responses[i] = HTTPService_serve(request);
            System_Memory_free(request);
            if (!responses[i]) {
                System_Console_writeLine("HTTPService_serve: No response", 0);
                Network_TCPSocket_close(sockets[i]);
                continue;
            }
        }

        if (System_Runtime_HitCTRLC) break;

        active += Network_TCPSocket_pollAny(sockets, socketC, Network_PollFlags_OUT, polls);
        for (System_Size i = 1; i < socketC; ++i) {
            if (polls[i] & Network_PollFlags_ERROR) {
                System_Console_writeLine("HTTPService_serve: POLLOUT: POLLERR", 0);
                continue;
            }
            if (!(polls[i] & Network_PollFlags_OUT)) continue;
            if (!sockets[i]) continue;
            if (!responses[i]) continue;

            System_Console_writeLine("HTTPService_serve: socket {0:uint}: sending message", 1, i);

            Network_TCPSocket_send(sockets[i], &responses[i]->source, Network_MessageFlags_NOSIGNAL);
            if (responses[i]->buffer.length)
                Network_TCPSocket_send(sockets[i], &responses[i]->buffer, Network_MessageFlags_NOSIGNAL);

            Network_TCPSocket_close(sockets[i]);
            System_Memory_free(responses[i]);
        }

        for (System_Size i = socketC; i; --i) {
            if (sockets[i - 1] && !sockets[i - 1]->socketId) {
                System_Console_writeLine("HTTPService_serve: socket {0:uint}: free", 1, i - 1);
                polls[i - 1] = 0;
                System_Memory_free(sockets[i - 1]);
                if (responses[i - 1]) System_Memory_free(responses[i - 1]);
                for (System_Size n = i; n < socketC; ++n) {
                    sockets[n - 1] = sockets[n];
                    polls[n - 1] = polls[n];
                    responses[n - 1] = responses[n];
                }
                sockets[socketC] = null;
                polls[socketC] = 0;
                responses[socketC] = null;
                --socketC;
            }
        }

        if (!active) System_Thread_millisleep(500);
    }

    for (System_Size i = 1; i < socketC; ++i) {
        if (sockets[i]) {
            System_Console_writeLine("HTTPService_serve: socket {0:uint}: finally free", 1, i);
            System_Memory_free(sockets[i]);
            if (responses[i]) System_Memory_free(responses[i]);
        }
    }

    Network_TCPSocket_close(sockets[0]);
    System_Memory_free(sockets[0]);
    return false;
}
