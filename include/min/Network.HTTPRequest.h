/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String)
#include "System.String.h"
#endif
#if !defined(have_System_String8Dictionary)
#include "System.String8Dictionary.h"
#endif
#if !defined(have_System_MemoryStream)
#include "System.MemoryStream.h"
#endif
#if !defined(have_Network_HTTPRequest)
#define have_Network_HTTPRequest

/** class Network.HTTPRequest  **/

typedef System_IntPtr Network_HTTPMethod;
enum {
    Network_HTTPMethod_GET = 1,
    Network_HTTPMethod_HEAD,
    Network_HTTPMethod_POST,
    Network_HTTPMethod_PUT,
    Network_HTTPMethod_OPTIONS,
    Network_HTTPMethod_DELETE,
};

typedef struct Network_MimeType {
    System_String8 extension;
    System_String8 name;
} * Network_MimeType;

const System_Size Network_MimeTypes_Capacity;

typedef struct Network_URI {

    System_String8 source;

    System_String8 queryString;

} * Network_URI;

export void Network_URI_free(Network_URI that);

typedef struct Network_HTTPRequest {
    struct System_Object base;

    Network_HTTPMethod method;

    struct Network_URI uri;

    System_String8 version;

    System_String8Dictionary header;

} * Network_HTTPRequest;

export struct System_Type Network_HTTPRequestType;

export void base_Network_HTTPRequest_free(Network_HTTPRequest that);

typedef struct Network_HTTPResponse {
    struct System_Object base;

    struct System_String head;

    Network_HTTPStatus status;

    System_String8Dictionary header;

    /* System_Bool keepAlive; */

    struct System_String body;

    System_MemoryStream stream;

} * Network_HTTPResponse;

export struct System_Type Network_HTTPResponseType;

typedef void delegate(Network_HTTPRequest_render)(Network_HTTPRequest request, Network_HTTPResponse response);

export void base_Network_HTTPResponse_free(Network_HTTPResponse that);
export Network_HTTPResponse Network_HTTPResponse_create(Network_HTTPStatus status);

#endif
