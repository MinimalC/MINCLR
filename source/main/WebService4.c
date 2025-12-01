/* Gemeinfrei. Public Domain. */
#include "../System.internal.h"
#include <min/System.h>

struct Network_MimeType  Network_MimeTypes[] = {
    { "", "" },
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

Network_HTTPRequest HTTPRequest_parse(System_String message) {
    Console_assert(message);
    Console_assert(message->length);

    Network_HTTPRequest httpRequest = new_Network_HTTPRequest();

    System_String8 string = message->value;
    System_Size remainSize = message->length;
    System_String8 contentType = null;
    System_String8 connection = null;
    while (true) {
        System_SSize linefeed = System_String8_indexOf__char(string, '\n');
        if (linefeed == -1) {
            System_Console_writeLine("HTTPRequest_parse: No linefeed", 0);
            goto HTTPRequest_parse_error;
        }
        remainSize -= linefeed + 1;
        string[linefeed] = '\0';
        if (linefeed > 0)
            if (string[linefeed - 1] == '\r')
                string[linefeed - 1] = '\0';
        if (linefeed < 2) {
            string += linefeed + 1;
            // System_Console_writeLine("HTTPRequest_parse: End of Header", 0);
            break;
        }
        if (!httpRequest->method) {
            System_String8 string1 = string;

            if (String8_equalsSubstring(string1, "GET", 3)) { httpRequest->method = Network_HTTPMethod_GET; string1 += 3; }
            else if (String8_equalsSubstring(string1, "HEAD", 4)) { httpRequest->method = Network_HTTPMethod_HEAD; string1 += 4; }
            else if (String8_equalsSubstring(string1, "POST", 4)) { httpRequest->method = Network_HTTPMethod_POST; string1 += 4; }
            else if (String8_equalsSubstring(string1, "PUT", 3)) { httpRequest->method = Network_HTTPMethod_PUT; string1 += 3; }
            else if (String8_equalsSubstring(string1, "OPTIONS", 7)) { httpRequest->method = Network_HTTPMethod_OPTIONS; string1 += 7; }
            else if (String8_equalsSubstring(string1, "DELETE", 6)) { httpRequest->method = Network_HTTPMethod_DELETE; string1 += 6; }
            if (!httpRequest->method) {
                System_Console_writeLine("HTTPRequest_parse: Unknown Method {0:string}", 1, string1);
                goto HTTPRequest_parse_error;
            }
            string1++[0] = '\0';

            System_SSize space = System_String8_indexOf__char(string1, ' ');
            if (space == -1) {
                System_Console_writeLine("HTTPRequest_parse: No Space after URI {0:string}", 1, string1);
                goto HTTPRequest_parse_error;
            }
            string1[space] = '\0';

            System_SSize questionMark = System_String8_indexOf__char(string1, '?');
            String8 queryString = null;
            if (questionMark != -1) {
                string1[questionMark] = '\0';
                queryString = string1 + questionMark + 1;
            }
            if (!String8_isNullOrEmpty(queryString)) {
                Network_HTTPRequest_parseQueryString(&httpRequest->query, queryString);
            }
            httpRequest->uri.source = System_String8_copy(string1);
            
            string1 += space + 1;

            if (!String8_equalsSubstring(string1, "HTTP/", 5)) {
                System_Console_writeLine("HTTPRequest_parse: No HTTP {0:string} {1:string}", 2, string1, httpRequest->uri.source);
                goto HTTPRequest_parse_error;
            }
            string1 += 5;
            System_Char8 version[8]; Stack_clear(version);
            System_String8_copyTo(string1, version);

            if (!String8_isNullOrEmpty(queryString))
                System_Console_writeLine("HTTPRequest_parse: {0:string} {1:string}?{2:string} HTTP/{3:string}", 4,
                    Network_HTTPMethod_toString(httpRequest->method), httpRequest->uri.source, queryString, version);
            else
                System_Console_writeLine("HTTPRequest_parse: {0:string} {1:string} HTTP/{2:string}", 3,
                    Network_HTTPMethod_toString(httpRequest->method), httpRequest->uri.source, version);
        }
        else {
            System_SSize dot = System_String8_indexOf__char(string, ':');
            if (dot == -1) {
                System_Console_writeLine("HTTPRequest_parse: No Header Name {0:string}", 1, string);
                goto HTTPRequest_parse_error;
            }
            string[dot] = '\0';
            
            String8 key = System_String8_copy(string);
            String8 value = System_String8_copy(string + dot + 2);
            if (String8_equals(key, "Content-Type")) contentType = value;
            if (String8_equals(key, "Connection")) connection = value;
            System_String8Dictionary_add(&httpRequest->header, key, value);
        }
        string += linefeed + 1;
    }
    if (String8_isNullOrEmpty(contentType)) ;
    else if (String8_equalsSubstring(contentType, "multipart/form-data; boundary=", 30)) {
        String8 boundary = contentType + 30;
        Size boundaryL = String8_get_Length(boundary);
        /* Console_write("HTTPRequest_parse: multipart/form-data with boundary", 0);
        Console_write__string_size(string, remainSize);
        Console_writeLineEmpty();
        Console_writeLine("<<<END", 0);*/
        while (true) {
            Size rn = String8_indexOf__char(string, '\n');
            if (rn == -1 || rn < 2) break;
            string[rn] = '\0'; string[rn - 1] = '\0';
            Console_writeLine("HTTPRequest_parse: {0:string}", 1, string);
            if (!String8_equalsSubstring(string + 2, boundary, boundaryL)) break;
            if (String8_equalsSubstring(string + 2 + boundaryL, "--", 2)) break;
            string += rn + 1;
            remainSize -= rn + 1;
            rn = String8_indexOf__char(string, '\n');
            if (rn == -1 || rn < 2) break;
            string[rn] = '\0'; string[rn - 1] = '\0';

            String8 content_disposition = null;
            String8 content_name = null;
            String8 content_type = null;
            String8 file_name = null;
            if (String8_equalsSubstring(string, "Content-Disposition", 19)) {
                String8 string1 = string;

                Size colon = String8_indexOf__char(string1, ':');
                if (colon == -1) break;
                string1[colon] = '\0'; if (string1[colon + 1] == ' ') ++colon;
                content_disposition = string1 + colon + 1;
                
                string1 += colon + 1;
                Size n = String8_indexOf(string1, "name=");
                if (n == -1) break;
                Size fn = String8_indexOf__char(string1 + n + 6, '"');
                if (fn == -1) break;
                string1[n + 6 + fn] = '\0';
                content_name = string1 + n + 6;
                Console_writeLine("HTTPRequest_parse: Content-Name {0:string}", 1, content_name);

                string1 += n + 6 + fn + 1;
                Size n1 = String8_indexOf(string1, "filename=");
                if (n1 != -1) {
                    Size fn1 = String8_indexOf__char(string1 + n1 + 10, '"');
                    if (fn1 == -1) break;
                    string1[n1 + 10 + fn1] = '\0';
                    file_name = string1 + n1 + 10;
                    Console_writeLine("HTTPRequest_parse: Content-FileName {0:string}", 1, file_name);
                    string1 += n1 + 10 + fn1 + 1;
                }

                string += rn + 1;
                remainSize -= rn + 1;
                rn = String8_indexOf__char(string, '\n');
                if (rn == -1) break;
                string[rn] = '\0'; string[rn - 1] = '\0';
            }
            else break;
            
            if (String8_equalsSubstring(string, "Content-Type", 12)) {
                Size colon = String8_indexOf__char(string, ':');
                if (colon == -1) break;
                string[colon] = '\0'; if (string[colon + 1] == ' ') ++colon;
                content_type = string + colon + 1;
                Console_writeLine("HTTPRequest_parse: Content-Type {0:string}", 1, content_type);

                string += rn + 1;
                remainSize -= rn + 1;
                rn = String8_indexOf__char(string, '\n');
                if (rn == -1) break;
                string[rn] = '\0'; string[rn - 1] = '\0';
            }

            if (rn < 2) {
                string += rn + 1;
                remainSize -= rn + 1;
                Size end = Memory_indexOf__other(string, remainSize, boundary, boundaryL);
                if (end == -1) break;                    
                String8 content_value = Memory_allocArray(typeof(Char8), end); Memory_copyTo(string, end - 4, content_value);
                if (!String8_isNullOrEmpty(file_name)) {
                    String content_container = Memory_allocClass(typeof(String));
                    content_container->length = end - 4;
                    content_container->value = content_value;
                    Console_writeLine("HTTPRequest_parse: Content-Value ... length {0:uint}", 1, end - 4);

                    VarDictionary_add(&httpRequest->files, String8_copy(file_name), content_container);
                    String8Dictionary_add(&httpRequest->form, String8_copy(content_name), String8_copy(file_name));
                }
                else {
                    Console_writeLine("HTTPRequest_parse: Content-Value {0:string}", 1, content_value);
                    String8Dictionary_add(&httpRequest->form, String8_copy(content_name), content_value);
                }
                string += end - 2;
                remainSize -= end - 2;
            }
            else break;
        }
    }
    else if (String8_equals(contentType, "application/x-www-form-urlencoded")) {
        if (!string) {
            Network_HTTPRequest_parseQueryString(&httpRequest->form, string);
        }
    }
    else if (String8_equals(contentType, "text/plain")) {
        while (true) {
            Size rn = String8_indexOf__char(string, '\n');
            if (rn == -1) break;
            string[rn] = '\0'; string[rn - 1] = '\0';
            Size eq = String8_indexOf__char(string, '=');
            if (eq != -1) {
                string[eq] = '\0';
                String8Dictionary_add(&httpRequest->form, String8_copy(string), String8_copy(string + eq + 1));
            }
            string += rn + 1;
        }
    }
    else {
        Console_writeLine("HTTPRequest_parse: Unknown Content-Type {0:string}", 1, contentType);
    }
    if (httpRequest->query.length) {
        System_Console_write__string("HTTPRequest_parse: Query ");
        for (Size m = 0 ; m < httpRequest->query.length; ++m) {
            System_Console_write("{0:string}{1:string}={2:string} ", 3, !m ? "?" : "&", 
                array_item(httpRequest->query.key, m), array_item(httpRequest->query.value, m)); 
        }
        System_Console_writeLineEmpty();
    }
    if (httpRequest->form.length) {
        System_Console_write__string("HTTPRequest_parse: Form ");
        for (Size m = 0 ; m < httpRequest->form.length; ++m) {
            System_Console_write("{0:string}{1:string}={2:string} ", 3, !m ? "?" : "&", 
                array_item(httpRequest->form.key, m), array_item(httpRequest->form.value, m)); 
        }
        System_Console_writeLineEmpty();
    }
    if (httpRequest->files.length) {
        System_Console_write__string("HTTPRequest_parse: Files ");
        for (Size m = 0 ; m < httpRequest->files.length; ++m) {
            System_Console_write("{0:string}{1:string} ", 2, array_item(httpRequest->files.key, m),
                m == httpRequest->files.length - 1 ? " " : ","); 
        }
        System_Console_writeLineEmpty();
    }
    if (connection) {
        /* if (String8_equalsSubstring(connection, "close", 5)) 
            httpRequest->connection = Network_HTTPConnection_Close; */
        if (String8_equalsSubstring(connection, "keep-alive", 10)) 
            httpRequest->connection = Network_HTTPConnection_KeepAlive;
    }

    return httpRequest;

HTTPRequest_parse_error:
    Memory_free(httpRequest);
    return null;
}

String8 ECSX_RootDirectoryName = null;

String8 ECSX_WWWDirectoryName = null;

String8 ECSX_TempDirectoryName = null;

VarDictionary ECSX_AssemblyCache = null;

void ECSX_updateTempDirectory() {
    if (!Directory_exists(ECSX_TempDirectoryName))
        if (!Directory_create(ECSX_TempDirectoryName)) {
            System_Console_writeLine__string(".temp directory not created.");
            return;
        }
    
    if (!ECSX_AssemblyCache) ECSX_AssemblyCache = System_Memory_allocClass(typeof(System_VarDictionary));
    System_DirectoryList current = System_Directory_list__recursive(ECSX_WWWDirectoryName, true);
    System_DirectoryList temp = System_Directory_list__recursive(ECSX_TempDirectoryName, true);

    for (Size o = 0; o < temp->length; ++o) {
        DirectoryEntry old_entry = &array_item(temp->value, o);
        if (old_entry->type == System_Directory_Type_RegularFile) {
            Size n = 0; for (; n < current->length; ++n) {
                DirectoryEntry new_entry = &array_item(current->value, n);
                if (new_entry->type == System_Directory_Type_RegularFile)
                    if (String8_compare(old_entry->name, new_entry->name) == String8_get_Length(new_entry->name)) break;
            }
            if (n == current->length) { // deleted
                VarDictionary_remove(ECSX_AssemblyCache, old_entry->name);
                String8 fileName = Path_combine(ECSX_TempDirectoryName, old_entry->name);
                if (File_delete(fileName))
                    Console_writeLine("ECSXService_serve: file deleted {0:string}", 1, fileName);
                else
                    Console_writeLine("ECSXService_serve: file not deleted {0:string}", 1, fileName);
                Memory_free(fileName);
            }
        }
    }
    for (Size o = temp->length; o; --o) {
        DirectoryEntry old_entry = &array_item(temp->value, o - 1);
        if (old_entry->type == System_Directory_Type_Directory) {
            Size n = current->length; for (; n; --n) {
                DirectoryEntry new_entry = &array_item(current->value, n - 1);
                if (new_entry->type == System_Directory_Type_Directory)
                    if (String8_compare(old_entry->name, new_entry->name) == String8_get_Length(new_entry->name)) break;
            }
            if (!n) { // deleted
                String8 directoryName = Path_combine(ECSX_TempDirectoryName, old_entry->name);
                if (Directory_remove(directoryName))
                    Console_writeLine("ECSXService_serve: directory deleted {0:string}", 1, directoryName);
                else
                    Console_writeLine("ECSXService_serve: directory not deleted {0:string}", 1, directoryName);
                Memory_free(directoryName);
            }
        }
    }
    Memory_free(current);
    Memory_free(temp);
}

System_Char8 pretext_C[] =
    "#define using_System\n"
    "#include <min/System.h>\n";

System_Char8 pretext_HTML[] =
    "<!DOCTYPE html>\n"
    "<html><head>\n"
    "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n";

IntPtr  ECSXService_serve_thread(Size argc, Var argv[]);

Network_HTTPResponse  ECSXService_serve(Network_HTTPRequest request, System_String8 requestPath, System_String8 text, System_Size fileSize) {

    String8 shortName = String8_copy(requestPath + String8_get_Length(ECSX_WWWDirectoryName));
    String8 ecsxName = String8_concat2("HTTP_", shortName);
    for (Size c = 0, length = String8_get_Length(ecsxName); c < length; ++c) {
        Char8 z = ecsxName[c];
        if (!c && (z < 0x41 || z > 0x5A) && (z < 0x61 || z > 0x7A)) {
            ecsxName[c] = '_';
            continue;
        }
        if ((z < 0x30 || z > 0x39) && (z < 0x41 || z > 0x5A) && (z < 0x61 || z > 0x7A)) {
            ecsxName[c] = '_';
            continue;
        }
    }
    String8 fileName1 = String8_concat2(shortName, ".o");
    String8_exchange(&fileName1, Path_combine(ECSX_TempDirectoryName, fileName1));
    struct FileInfo fileInfo0; Stack_clear(fileInfo0); FileInfo_init(&fileInfo0, requestPath);
    struct FileInfo fileInfo1; Stack_clear(fileInfo1); FileInfo_init(&fileInfo1, fileName1);
    if (fileInfo1.status.mode & System_FileInfo_Type_Regular) {
        if (fileInfo0.status.modifyTime.sec <= fileInfo1.status.modifyTime.sec) {
            ECSX_updateTempDirectory();
            System_Console_writeLine("ECSXService_serve: using old {0:string}", 1, fileName1);
            goto ECSXService_serve_render;
        }
    }
    struct System_MemoryStream stream; Stack_clear(stream);
    MemoryStream_write__string_size(&stream, pretext_C, sizeof(pretext_C) - 1);
    MemoryStream_write(&stream, "void {0:string}(Network_HTTPRequest request, Network_HTTPResponse response) ", 1, ecsxName);
    MemoryStream_write__string(&stream, "{\n");
    MemoryStream_write__string(&stream, "MemoryStream_write__string(&response->stream,\n\"");

    System_Size C = 0, ecsx_qualified = 0;
    for (Size c = 0; c < fileSize; ++c) {
        if (C == 0) {
            if (c + 1 < fileSize && text[c] == '<' && text[c + 1] == '%') {
                ecsx_qualified = 1;
                MemoryStream_write__string(&stream, "\");\n");
                if (c + 2 < fileSize && text[c + 2] == '=') {
                    MemoryStream_write__string(&stream, "MemoryStream_writeLine(&response->stream,");
                    C = 2; c += 2;
                    continue;
                }
                C = 1; ++c;
                continue;
            }
            if (text[c] == '\n') {
                MemoryStream_write__string(&stream, "\\n\"\n\"");
                continue;
            }
            if (text[c] == '\\') {
                MemoryStream_write__string(&stream, "\\\\");
                continue;
            }
            if (text[c] == '"') {
                MemoryStream_write__string(&stream, "\\\"");
                continue;
            }
        }
        if (C == 1) {
            if (c + 1 < fileSize && text[c] == '%' && text[c + 1] == '>') {
                MemoryStream_write__string(&stream, "MemoryStream_write__string(&response->stream,\n\"");
                C = 0; ++c; ecsx_qualified = 2;
                continue;
            }
        }
        if (C == 2) {
            if (c + 1 < fileSize && text[c] == '%' && text[c + 1] == '>') {
                MemoryStream_write__string(&stream, ");\n");
                MemoryStream_write__string(&stream, "MemoryStream_write__string(&response->stream,\n\"");
                C = 0; ++c; ecsx_qualified = 2;
                continue;
            }
        }
        MemoryStream_write__char(&stream, text[c]);
    }
    if (C == 0) {
        MemoryStream_write__string(&stream, "\");\n");
    }
    MemoryStream_write__string(&stream, "}\n");

    if (ecsx_qualified < 1) {
        System_Console_writeLine__string("ECSXService_serve: disqualified");

        MemoryStream_free(&stream);
        Memory_free(ecsxName);
        Memory_free(fileName1);
        Memory_free(shortName);
        return null;
    }
    if (ecsx_qualified < 2) {
        System_Console_writeLine__string("ECSXService_serve: unqualified");

        Network_HTTPResponse response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
        response->body.length = fileSize;
        response->body.value = Memory_addReference(text);
        response->mimeType = request->mimeType;
        
        MemoryStream_free(&stream);
        Memory_free(ecsxName);
        Memory_free(fileName1);
        Memory_free(shortName);
        return response;
    }

    System_Size bufferSize = 0;
    System_String8 buffer = MemoryStream_final__size(&stream, &bufferSize);

    ECSX_updateTempDirectory();

    String8 fileName2 = String8_concat2(shortName, ".c");
    String8 fileName2_directory = Path_getDirectoryName(fileName2);
    if (!Directory_exists(fileName2_directory))
        if (Directory_create__recursive(ECSX_TempDirectoryName, fileName2_directory))
            Console_writeLine("ECSXService_serve: directory created {0:string}{1:string}", 2, ECSX_TempDirectoryName, fileName2_directory);
        else 
            Console_writeLine("ECSXService_serve: directory not created {0:string}{1:string}", 2, ECSX_TempDirectoryName, fileName2_directory);
    Memory_free(fileName2_directory);
    String8_exchange(&fileName2, Path_combine(ECSX_TempDirectoryName, fileName2));

    struct File output; Stack_clear(output);
    if (stack_System_File_open(&output, fileName2, File_Mode_readWrite | File_Mode_create | File_Mode_truncate))
        File_write__string_size(&output, buffer, bufferSize);
    File_free(&output);
    Memory_free(buffer);

    String8 fileName3 = String8_concat2(shortName, ".gcc.output");
    String8_exchange(&fileName3, Path_combine(ECSX_TempDirectoryName, fileName3));
    stack_System_File_open(&output, fileName3, File_Mode_readWrite | File_Mode_create | File_Mode_truncate);
    System_File_write__string_size(&output, pretext_HTML, sizeof(pretext_HTML) - 1);
    System_File_write__string(&output, "<title>GCC compiler error</title>\n");
    System_File_write__string(&output, "</head><body><h3>GCC compiler error</h3><pre>\n");

    Size gcc = System_Console_execute__stdout_stderr("/usr/bin/gcc", null, &output, 13, 
        "gcc", "-I../include", "-L.", "-l:System.so", "-nostdlib", "-nostartfiles", "-nodefaultlibs", "-ffreestanding", 
        "-shared", "-fPIC", "-o", fileName1, fileName2);

    System_File_write__string(&output, "</pre></body></html>\n");
    Memory_free(fileName2);

    if (gcc) {
        System_Console_writeLine__string("ECSXService_serve: unqualified, GCC compiler error");

        File_set_Position(&output, 0);
        bufferSize = File_get_Length(&output);
        buffer = Memory_allocArray(typeof(Char8), bufferSize + 1);
        System_File_read(&output, buffer, bufferSize);

        Network_HTTPResponse response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
        response->body.length = bufferSize;
        response->body.value = buffer;
        response->mimeType = request->mimeType;

        File_free(&output);
        Memory_free(fileName3);
        Memory_free(ecsxName);
        Memory_free(fileName1);
        Memory_free(shortName);
        return response;
    }
    File_free(&output);
    File_delete(fileName3);
    Memory_free(fileName3);
                
    System_Console_writeLine("ECSXService_serve: using new {0:string}", 1, fileName1);

ECSXService_serve_render:

    if (!System_VarDictionary_containsKey(ECSX_AssemblyCache, fileName1)) {
        System_ELF64Assembly assembly = System_Memory_allocClass(typeof(System_ELF64Assembly));
        System_ELF64Assembly_read(assembly, fileName1);
        System_ELF64Assembly_link(assembly);
        VarDictionary_add(ECSX_AssemblyCache, fileName1, assembly);
    }

    Network_HTTPResponse response = Network_HTTPResponse_create(Network_HTTPStatus_OK);
    response->connection = Network_HTTPConnection_Close;
    response->mimeType = request->mimeType;

    response->asyncFileName = fileName1;
    response->asyncECSXName = ecsxName;
    response->asyncThread = System_Thread_create(ECSXService_serve_thread, 4, fileName1, ecsxName, request, response);

    Memory_free(shortName);
    return response;
}

IntPtr  ECSXService_serve_thread(Size argc, Var argv[]) {

    if (argc < 4) return false;

    String8 fileName1 = argv[0];
    String8 ecsxName = argv[1];

    if (!System_VarDictionary_containsKey(ECSX_AssemblyCache, fileName1)) {
        Console_writeLine("ECSXService_serve: No ELFAssembly {0:string}", 1, fileName1);
        return null;
    }
    System_ELF64Assembly assembly = System_VarDictionary_get_value(ECSX_AssemblyCache, fileName1);

    function_Network_HTTPRequest_render HTTP_render = null;
    System_ELFAssembly_Symbol symbol1 = System_ELF64Assembly_getSymbol(assembly, ecsxName);
    if (symbol1 && symbol1->value) {
        HTTP_render = (function_Network_HTTPRequest_render)((System_Size)assembly->link + symbol1->value);
    }
    if (!HTTP_render) {
        Console_writeLine("ECSXService_serve: No ELFSymbol (function_Network_HTTPRequest_render) {0:string}", 1, ecsxName);
        return null;
    }
    Console_writeLine("ECSXService_serve: ELFSymbol {0:string}", 1, ecsxName);

    Network_HTTPRequest request = argv[2];
    Network_HTTPResponse response = argv[3];

    HTTP_render(request, response);

    System_String8 finalText = System_Memory_allocStaticArray(typeof(System_Char8), response->stream.size);
    System_Memory_copyTo(response->stream.buffer, response->stream.size, finalText);
    response->body.value = finalText;
    response->body.length = response->stream.size;

    MemoryStream_close(&response->stream);
    return true;
}

Network_HTTPResponse HTTPService_serve(Network_HTTPRequest request) {
    Network_HTTPResponse response = null;

    for (System_Size i = 0; i < request->header.length; ++i) {
        System_String8 key = array(request->header.key)[i];
        System_String8 value = array(request->header.value)[i];
        System_Console_writeLine("HTTPService_serve: {0:string}: {1:string}", 2, key, value);
    }

    System_Console_writeLine("HTTPService_serve: request->uri.source {0:string}", 1, request->uri.source);

    // Get a worker for the URI
    System_String8 requestPath = Path_combine(ECSX_WWWDirectoryName, request->uri.source);
    if (!String8_startsWith(requestPath, ECSX_WWWDirectoryName)) {
        System_Console_writeLine("HTTPService_serve: 500 Error {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_Error);
        System_Memory_free(requestPath);
        goto respond;
    }
    struct System_FileInfo fileInfo; Stack_clear(fileInfo); FileInfo_init(&fileInfo, requestPath);
    if (fileInfo.status.mode & FileInfo_Type_Directory) {
        System_Console_writeLine("HTTPService_serve: Directory {0:string}", 1, requestPath);
        System_String8_exchange(&requestPath, Path_combine(requestPath, "/index.html"));
        FileInfo_init(&fileInfo, requestPath);
    }
    if (!(fileInfo.status.mode & FileInfo_Type_Regular)) {
        System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
        System_Memory_free(requestPath);
        goto respond;
    }
    System_String8 requestExt = System_Path_getFileNameExt(requestPath);
    System_Size mime = 0;
    while (++mime < Network_MimeTypes_Capacity)
        if (String8_equals(requestExt, Network_MimeTypes[mime].extension)) break;
    if (mime == Network_MimeTypes_Capacity) mime = 0;
    request->mimeType = mime;
    System_Memory_free(requestExt);
    if (!request->mimeType) {
        System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
        System_Memory_free(requestPath);
        goto respond;
    }
    Size fileSize = fileInfo.status.size;
    if (fileSize > 2 && fileSize < 0x400000) { // Just serve not 4MB
        String8 buffer = Memory_allocArray(typeof(Char8), fileSize + 1);
        struct File file; Stack_clear(file); 
        if (stack_System_File_open(&file, requestPath, System_File_Mode_readOnly)) 
            System_File_read(&file, buffer, fileSize);
        System_File_free(&file);
        if (response = ECSXService_serve(request, requestPath, buffer, fileSize)) {
            System_Memory_free(requestPath);
            System_Memory_free(buffer);
            goto respond;
        }
        System_Console_writeLine("HTTPService_serve: File {0:string}", 1, requestPath);
        response = Network_HTTPResponse_create(Network_HTTPStatus_OK);
        response->body.length = fileSize;
        response->body.value = buffer;
        response->connection = Network_HTTPConnection_Close;
        response->mimeType = request->mimeType;
        System_Memory_free(requestPath);
        goto respond;
    }

    System_Console_writeLine("HTTPService_serve: 404 FileNotFound {0:string}", 1, requestPath);
    response = Network_HTTPResponse_create(Network_HTTPStatus_FileNotFound);
    System_Memory_free(requestPath);
    
respond:

    return response;
}

void HTTPService_serve_response(Network_HTTPResponse response) {

    System_String8Dictionary_add(response->header, "Content-Length", System_UInt64_toString8base10(response->body.length));
    System_String8Dictionary_add(response->header, "Content-Type", Network_MimeTypes[response->mimeType].name);
    /* if (response->connection == Network_HTTPConnection_KeepAlive)
        System_String8Dictionary_add(response->header, "Connection", "keep-alive"); else */ 
    if (response->connection == Network_HTTPConnection_Close)
        System_String8Dictionary_add(response->header, "Connection", "close");

    struct MemoryStream scratch; Stack_clear(scratch);
    MemoryStream_writeLine(&scratch, "HTTP/1.1 {0:uint} {1:string}\r", 2, response->status, Network_HTTPStatus_toString(response->status));
    for (System_Size i = 0; i < response->header->length; ++i) {
        System_String8 key = array(response->header->key)[i];
        System_String8 value = array(response->header->value)[i];
        MemoryStream_writeLine(&scratch, "{0:string}: {1:string}\r", 2, key, value);
    }
    MemoryStream_write__string(&scratch, "\r\n");
    response->head.value = MemoryStream_final__size(&scratch, &response->head.length);

    if (response->body.length && System_String8_startsWith(Network_MimeTypes[response->mimeType].name, "text/"))
        System_Console_writeLine("HTTPResponse_toMessage: {0:string}{1:string}", 2, response->head.value, response->body.value);
    else
        System_Console_writeLine("HTTPResponse_toMessage: {0:string}", 1, response->head.value);
}

__volatile__ System_Bool System_Runtime_HitCTRLC = false;

void System_Runtime_CTRLC(System_Signal_Number number) {
    System_Runtime_HitCTRLC = true;
}

void System_Runtime_sigfault(System_Signal_Number number, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: number {1:uint32}, errno {2:uint32}, code {3:uint32}, sigfault.address {4:uint:hex}", 5,
        System_Signal_Number_toString(number), info->number, info->errno, info->code, info->sigfault.address);
    System_Thread_terminate(false);
}

int System_Runtime_main(int argc, String8 argv[]) {

    if (argc < 1) {
        System_Console_writeLine__string("Usage: WebService <directory>");
        return false;
    }

    struct System_Signal signal; System_Stack_clear(signal);
    System_Signal_add(&signal, System_Signal_Number_SIGINT);
    System_Signal_add(&signal, System_Signal_Number_SIGILL);
    System_Signal_add(&signal, System_Signal_Number_SIGFPE);
    System_Signal_add(&signal, System_Signal_Number_SIGSEGV);
    System_Signal_unblock(&signal);
    System_Signal_handle(System_Signal_Number_SIGINT, System_Runtime_CTRLC);
    System_Signal_act(System_Signal_Number_SIGILL, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGFPE, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGSEGV, System_Runtime_sigfault);

    if (!File_exists("System.so")) {
        System_Console_writeLine__string("MINCLR library not found");
        return false;
    }
    ECSX_RootDirectoryName = argc > 1 ? String8_copy(argv[1]) : Directory_get_current();
    Size l = String8_get_Length(ECSX_RootDirectoryName);
    if (FileInfo_isLink(ECSX_RootDirectoryName))
        String8_exchange(&ECSX_RootDirectoryName, FileInfo_readLink(ECSX_RootDirectoryName));
    if (!Directory_exists(ECSX_RootDirectoryName)) {
        System_Console_writeLine__string("Directory not found.");
        Memory_free(ECSX_RootDirectoryName);
        return false;
    }
    ECSX_WWWDirectoryName = Path_combine(ECSX_RootDirectoryName, "/www");
    if (FileInfo_isLink(ECSX_WWWDirectoryName))
        String8_exchange(&ECSX_WWWDirectoryName, FileInfo_readLink(ECSX_WWWDirectoryName));
    if (!Directory_exists(ECSX_WWWDirectoryName)) {
        System_Console_writeLine__string("www directory not found.");
        Memory_free(ECSX_RootDirectoryName);
        Memory_free(ECSX_WWWDirectoryName);
        return false;
    }
    ECSX_TempDirectoryName = Path_combine(ECSX_RootDirectoryName, "/.temp");
    if (FileInfo_isLink(ECSX_TempDirectoryName))
        String8_exchange(&ECSX_TempDirectoryName, FileInfo_readLink(ECSX_TempDirectoryName));
    ECSX_updateTempDirectory();

    Network_TCPSocket sockets[64]; Stack_clear(sockets); System_Size socketC = 1;
    Network_PollFlags polls[64]; Stack_clear(polls);
    Network_HTTPResponse responses[64]; Stack_clear(responses);

    sockets[0] = new_Network_TCPSocket__flags(/* Network_SocketType_NONBLOCK */ Network_SocketType_CLOSEONEXEC);

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

        System_Size active = Network_TCPSocket_pollAny(sockets, socketC, Network_PollFlags_IN | Network_PollFlags_ERROR, polls);
        for (System_Size i = 0; i < socketC; ++i) {
            if (!sockets[i] || !sockets[i]->socketId) continue;
            if (polls[i] & Network_PollFlags_ERROR) {
                System_Console_writeLine("HTTPService_serve: Socket {0:uint}: POLLERROR", 1, i);
                Network_TCPSocket_close(sockets[i]);
                System_Memory_free(sockets[i]);
                continue;
            }
            if (!(polls[i] & Network_PollFlags_IN)) continue;
            if (i == 0) {
                if (socketC == 64) {
                    System_Console_writeLine("HTTPService_serve: NO MORE ACCEPTs!", 0);
                    continue;
                }
                Network_TCPSocket incoming0 = Network_TCPSocket_accept__flags(sockets[0], Network_SocketType_NONBLOCK | Network_SocketType_CLOSEONEXEC);
                if (incoming0) {
                    Network_TCPSocket_setSocketOption(incoming0, Network_SocketOption_LINGER, 1UL << 32);

                    System_Console_writeLine("HTTPService_serve: Socket {0:uint}: ACCEPT0:", 1, socketC);
                    sockets[socketC++] = incoming0;
                }
                /* Network_TCPSocket incoming[8]; System_Stack_clear(incoming);
                for (System_Size n = 0; n < 8; ++n) {
                    incoming[n] = Network_TCPSocket_accept__flags(sockets[0], Network_SocketType_NONBLOCK | Network_SocketType_CLOSEONEXEC);
                    if (incoming[n]) {
                        Network_TCPSocket_setSocketOption(incoming[n], Network_SocketOption_LINGER, 1UL << 32);

                        System_Console_writeLine("HTTPService_serve: Socket {0:uint}: ACCEPT0:", 1, socketC);
                        sockets[socketC++] = incoming[n];
                    }
                }*/
                continue;
            }

            System_Console_writeLine("HTTPService_serve: Socket {0:uint}: receiving message:", 1, i);
            System_String message = Network_TCPSocket_receive__flags(sockets[i], 0);
            if (!message) {
                System_Console_writeLine("HTTPService_serve: No Message", 0);
                Network_TCPSocket_close(sockets[i]);
                System_Memory_free(sockets[i]);
                continue;
            }
            Network_HTTPRequest request = HTTPRequest_parse(message);
            System_Memory_free(message);
            if (!request) {
                System_Console_writeLine("HTTPService_serve: Message not parsed", 0);
                Network_TCPSocket_close(sockets[i]);
                System_Memory_free(sockets[i]);
                continue;
            }
            responses[i] = HTTPService_serve(request);
            System_Memory_free(request);
            if (!responses[i]) {
                System_Console_writeLine("HTTPService_serve: No response", 0);
                Network_TCPSocket_close(sockets[i]);
                System_Memory_free(sockets[i]);
                continue;
            }
        }

        if (System_Runtime_HitCTRLC) break;

        active += Network_TCPSocket_pollAny(sockets, socketC, Network_PollFlags_OUT | Network_PollFlags_ERROR, polls);
        for (System_Size i = 1; i < socketC; ++i) {
            if (!sockets[i] || !sockets[i]->socketId) continue;
            if (polls[i] & Network_PollFlags_ERROR) {
                System_Console_writeLine("HTTPService_serve: Socket {0:uint}: POLLERROR", 1, i);
                Network_TCPSocket_close(sockets[i]);
                System_Memory_free(sockets[i]);
                continue;
            }
            if (!(polls[i] & Network_PollFlags_OUT)) continue;
            if (!responses[i]) continue;
            if (responses[i]->asyncThread && !System_Thread_join__dontwait(responses[i]->asyncThread, true)) continue;
            
            System_Console_writeLine("HTTPService_serve: Socket {0:uint}: sending message.", 1, i);
            
            HTTPService_serve_response(responses[i]);

            if (responses[i]->head.length)
                Network_TCPSocket_send(sockets[i], &responses[i]->head, Network_MessageFlags_NOSIGNAL);
            if (responses[i]->body.length)
                Network_TCPSocket_send(sockets[i], &responses[i]->body, Network_MessageFlags_NOSIGNAL);

            System_Memory_free(responses[i]);
            Network_TCPSocket_close(sockets[i]);
            System_Memory_free(sockets[i]);
        }

        for (System_Size i = socketC; i; --i) {
            if (!sockets[i - 1] || !sockets[i - 1]->socketId) {
                System_Console_writeLine("HTTPService_serve: Socket {0:uint}: free.", 1, i - 1);
                if (responses[i - 1]) System_Memory_free(responses[i - 1]);
                if (sockets[i - 1]) System_Memory_free(sockets[i - 1]);
                if (polls[i - 1]) polls[i - 1] = 0;
                for (System_Size n = i; n < socketC; ++n) {
                    responses[n - 1] = responses[n];
                    sockets[n - 1] = sockets[n];
                    polls[n - 1] = polls[n];
                }
                responses[socketC] = null;
                sockets[socketC] = null;
                polls[socketC] = 0;
                --socketC;
            }
        }

        if (!active) { // System_Thread_microsleep(500);
            Network_TCPSocket incoming0 = Network_TCPSocket_accept__flags(sockets[0], Network_SocketType_NONBLOCK | Network_SocketType_CLOSEONEXEC);
            if (incoming0) {
                Network_TCPSocket_setSocketOption(incoming0, Network_SocketOption_LINGER, 1UL << 32);

                System_Console_writeLine("HTTPService_serve: Socket {0:uint}: ACCEPT1:", 1, socketC);
                sockets[socketC++] = incoming0;
            }
        }
    }

    for (System_Size i = 0; i < socketC; ++i) {
        if (responses[i]) System_Memory_free(responses[i]);
        if (sockets[i]) {
            System_Console_writeLine("HTTPService_serve: Socket {0:uint}: finally free.", 1, i);
            Network_TCPSocket_close(sockets[i]);
            System_Memory_free(sockets[i]);
        }
    }

    System_Memory_free(ECSX_TempDirectoryName);
    System_Memory_free(ECSX_WWWDirectoryName);
    System_Memory_free(ECSX_RootDirectoryName);
    System_Memory_free(ECSX_AssemblyCache);
    return false;
}
