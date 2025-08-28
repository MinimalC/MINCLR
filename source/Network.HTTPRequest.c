/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_String)
#include <min/System.String.h>
#endif
#if !defined(have_System_String8Dictionary)
#include <min/System.String8Dictionary.h>
#endif
#if !defined(have_Network_HTTPRequest)
#include <min/Network.HTTPRequest.h>
#endif
#if !defined(code_Network_HTTPRequest)
#define code_Network_HTTPRequest

System_String8 Network_HTTPStatus_toString(Network_HTTPStatus value) {
    switch (value) {
    case Network_HTTPStatus_OK: return "OK";
    case Network_HTTPStatus_MovedPermanently: return "MovedPermanently";
    case Network_HTTPStatus_SeeOther: return "SeeOther";
    case Network_HTTPStatus_FileNotFound: return "FileNotFound";
    case Network_HTTPStatus_Error: return "Error";
    default: return "Unknown";
} }

System_String8 Network_HTTPMethod_toString(Network_HTTPMethod value) {
    switch (value) {
    case Network_HTTPMethod_GET: return "GET";
    case Network_HTTPMethod_HEAD: return "HEAD";
    case Network_HTTPMethod_POST: return "POST";
    case Network_HTTPMethod_PUT: return "PUT";
    case Network_HTTPMethod_OPTIONS: return "OPTIONS";
    case Network_HTTPMethod_DELETE: return "DELETE";
    default: return "Unknown";
} }

void Network_URI_free(Network_URI that) {
    if (that->source) System_Memory_free(that->source);
}

/** struct Network_HTTPRequest  **/

Network_HTTPRequest  new_Network_HTTPRequest() {
    Network_HTTPRequest that = (Network_HTTPRequest)System_Memory_allocClass(typeof(Network_HTTPRequest));
    Network_HTTPRequest_init(that);
    return that;
}

void  Network_HTTPRequest_init(Network_HTTPRequest that) {
    System_String8Dictionary_init(&that->header);
    System_String8Dictionary_init(&that->query);
    System_String8Dictionary_init(&that->form);
    System_VarDictionary_init(&that->files);
}

void Network_HTTPRequest_free(Network_HTTPRequest that) {
    Network_URI_free(&that->uri);
    System_String8Dictionary_free(&that->header);
    System_String8Dictionary_free(&that->query);
    System_String8Dictionary_free(&that->form);
    System_VarDictionary_free(&that->files);
}

struct System_Type_FunctionInfo Network_HTTPRequestTypeFunctions[] = {
    { .function = base_System_Object_free, .value = Network_HTTPRequest_free },
    { .function = base_System_Object_init, .value = Network_HTTPRequest_init },
};

struct System_Type Network_HTTPRequestType = {
    .base = { .type = typeof(System_Type) },
    .name = "HTTPRequest",
    .size = sizeof(struct Network_HTTPRequest),
    .baseType = &System_ObjectType,
    .functions = { .length = sizeof_array(Network_HTTPRequestTypeFunctions), .value = &Network_HTTPRequestTypeFunctions, },
};

Network_HTTPResponse new_Network_HTTPResponse() {
    Network_HTTPResponse that = System_Memory_allocClass(typeof(Network_HTTPResponse));
    Network_HTTPResponse_init(that);
    return that;
}

void Network_HTTPResponse_init(Network_HTTPResponse that) {
    that->header = System_Memory_allocClass(typeof(System_String8Dictionary));
}

Network_HTTPResponse Network_HTTPResponse_create(Network_HTTPStatus status) {

    Network_HTTPResponse response = System_Memory_allocClass(typeof(Network_HTTPResponse));
    response->header = System_Memory_allocClass(typeof(System_String8Dictionary));
    response->status = status;
    return response;
}

void Network_HTTPResponse_free(Network_HTTPResponse that) {
    System_Memory_free(that->header);
    System_String_free(&that->head);
    System_String_free(&that->body);
    MemoryStream_free(&that->stream);
}

struct System_Type_FunctionInfo Network_HTTPResponseTypeFunctions[] = {
    { .function = base_System_Object_free, .value = Network_HTTPResponse_free },
    { .function = base_System_Object_init, .value = Network_HTTPResponse_init },
};

struct System_Type Network_HTTPResponseType = {
    .base = { .type = typeof(System_Type) },
    .name = "HTTPResponse",
    .size = sizeof(struct Network_HTTPResponse),
    .baseType = &System_ObjectType,
    .functions = { .length = sizeof_array(Network_HTTPResponseTypeFunctions), .value = &Network_HTTPResponseTypeFunctions, },
};

#endif
