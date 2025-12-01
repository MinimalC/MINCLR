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

typedef System_UInt8 Network_HTTPMethod;
export System_String8 Network_HTTPMethod_toString(Network_HTTPMethod value);
enum {
    Network_HTTPMethod_GET = 1,
    Network_HTTPMethod_HEAD,
    Network_HTTPMethod_POST,
    Network_HTTPMethod_PUT,
    Network_HTTPMethod_OPTIONS,
    Network_HTTPMethod_DELETE,
};

typedef System_UInt16 Network_HTTPStatus;
export System_String8 Network_HTTPStatus_toString(Network_HTTPStatus value);
enum {
    Network_HTTPStatus_OK = 200,
    Network_HTTPStatus_MovedPermanently = 301,
    Network_HTTPStatus_SeeOther = 303,
    Network_HTTPStatus_FileNotFound = 404,
    Network_HTTPStatus_Error = 500,
};

typedef System_UInt8 Network_HTTPConnection;
export System_String8 Network_HTTPConnection_toString(Network_HTTPConnection value);
enum {
    Network_HTTPConnection_Close,
    Network_HTTPConnection_KeepAlive,
    Network_HTTPConnection_Upgrade,
};

typedef System_UInt8 Network_HTTPUpgrade;
export System_String8 Network_HTTPUpgrade_toString(Network_HTTPUpgrade value);
enum {
    Network_HTTPUpgrade_None,
    Network_HTTPUpgrade_WebSocket,
};

typedef struct Network_MimeType {
    System_String8 extension;
    System_String8 name;
} * Network_MimeType;

const System_Size Network_MimeTypes_Capacity;

typedef struct Network_URI {

    System_String8 source;

} * Network_URI;

export void Network_URI_free(Network_URI that);

typedef struct Network_HTTPRequest {
    struct System_Object base;

    Network_HTTPMethod method;
    
    System_UInt8 mimeType;
    
    Network_HTTPConnection connection;

    Network_HTTPUpgrade upgrade;

    struct Network_URI uri;

    struct System_String8Dictionary header;

    struct System_String8Dictionary query;

    struct System_String8Dictionary form;

    struct System_VarDictionary files;

} * Network_HTTPRequest;

export struct System_Type Network_HTTPRequestType;

export void Network_HTTPRequest_parseQueryString(String8Dictionary that, System_String8 queryString);
export Network_HTTPRequest  new_Network_HTTPRequest();
export void  Network_HTTPRequest_init(Network_HTTPRequest that);
export void  Network_HTTPRequest_free(Network_HTTPRequest that);

typedef struct Network_HTTPResponse {
    struct System_Object base;

    struct System_String head;

    System_String8Dictionary header;

    Network_HTTPStatus status;

    System_UInt8 mimeType;

    Network_HTTPConnection connection;

    Network_HTTPUpgrade upgrade;

    struct System_String body;

    struct System_MemoryStream stream;

    System_Thread asyncThread;

    System_String8 asyncFileName;

    System_String8 asyncECSXName;

} * Network_HTTPResponse;

export struct System_Type Network_HTTPResponseType;

typedef void delegate(Network_HTTPRequest_render)(Network_HTTPRequest request, Network_HTTPResponse response);

export Network_HTTPResponse  new_Network_HTTPResponse();
export void  Network_HTTPResponse_init(Network_HTTPResponse that);
export Network_HTTPResponse  Network_HTTPResponse_create(Network_HTTPStatus status);
export void  Network_HTTPResponse_free(Network_HTTPResponse that);

#endif
