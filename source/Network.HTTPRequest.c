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

/** struct Network_HTTPRequest  **/

void Network_URI_free(Network_URI that) {
    if (that->source) System_Memory_free(that->source);
}

void base_Network_HTTPRequest_free(Network_HTTPRequest that) {
    Network_URI_free(&that->uri);
    System_String8Dictionary_free(&that->header);
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

void base_Network_HTTPResponse_free(Network_HTTPResponse that) {
    if (that->header) System_Memory_free(that->header);
    System_String_free(&that->head);
    System_String_free(&that->body);
    if (that->stream) System_Memory_free(that->stream);
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
    response->status = status;
    return response;
}

#endif
