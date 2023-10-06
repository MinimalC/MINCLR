/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_UInt32)
#include <min/System.values.auto.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_Network_TCPSocket)
#include <min/Network.TCPSocket.h>
#endif
#if !defined(code_Network_TCPSocket)
#define code_Network_TCPSocket

/*# Network.TCPSocket #*/

Network_TCPSocket  Network_TCPSocket_create() {

    Network_TCPSocket that = System_Memory_allocClass(typeof(Network_TCPSocket));

    that->socketId = System_Syscall_socket(Network_AddressFamily_IP4, Network_SocketType_STREAM, 0);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_create Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));

    return that;
}

void  base_Network_TCPSocket_close(Network_TCPSocket that) {
    if (!that->socketId) return;
    System_Syscall_close((System_Var)that->socketId);
    that->socketId = null;
}

System_IntPtr  base_Network_TCPSocket_getSocketOption(Network_TCPSocket that, Network_SocketOption option) {
    System_IntPtr reture = 0;
    System_Size retureSize = sizeof(System_IntPtr);
    System_Syscall_getsockopt(that->socketId, Network_SocketLevel_SOCKET, option, &reture, &retureSize);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_getSocketOption Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
    return reture;
}

void  base_Network_TCPSocket_setSocketOption(Network_TCPSocket that, Network_SocketOption option, System_IntPtr value) {
    System_Syscall_setsockopt(that->socketId, Network_SocketLevel_SOCKET, option, &value, sizeof(System_IntPtr));
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_setSocketOption Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void  base_Network_TCPSocket_bind(Network_TCPSocket that, Network_IP4Address address, System_UInt16 port) {

    struct Network_SocketAddress socketAddress; System_Stack_zero(socketAddress);
    socketAddress.family = Network_AddressFamily_IP4;
    socketAddress.port = System_UInt16_toNetworkOrder(port);
    for (Size i = 0; i < 16; ++i) {
        if (i < 4) socketAddress.address[i] = address.address[i];
        else socketAddress.address[i] = 0;
    }
    /*System_Console_writeLine("Network_SocketAddress before: family {0:uint16}, port {1:uint16}, address {2:uint8:hex}.{3:uint8:hex}.{4:uint8:hex}.{5:uint8:hex}", 6, 
        socketAddress.family, socketAddress.port, socketAddress.address[0], socketAddress.address[1], socketAddress.address[2], socketAddress.address[3]);*/

    System_Syscall_bind(that->socketId, &socketAddress, sizeof(struct Network_SocketAddress));
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_bind Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void  base_Network_TCPSocket_listen(Network_TCPSocket that, System_Size backlog) {
    System_Syscall_listen(that->socketId, backlog);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_listen Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

Network_TCPSocket  base_Network_TCPSocket_accept(Network_TCPSocket that) {
    return base_Network_TCPSocket_accept__flags(that, 0);
}

Network_TCPSocket  base_Network_TCPSocket_accept__flags(Network_TCPSocket that, System_IntPtr flags) {
    struct Network_SocketAddress address; System_Stack_zero(address);
    System_Size addressLength = sizeof(struct Network_SocketAddress);
    System_IntPtr reture = System_Syscall_accept(that->socketId, &address, &addressLength, flags);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) {
        System_Console_writeLine("Network_TCPSocket_accept Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
        return null;
    }
    Network_TCPSocket new = (Network_TCPSocket)System_Memory_allocClass(typeof(Network_TCPSocket)); 
    new->socketId = reture;
    return new;
}

Network_MessageHeader  base_Network_TCPSocket_receiveMessage(Network_TCPSocket that, Network_MessageFlags flags) {

    UInt8 body[System_UInt16_Max]; System_Stack_zero(body);

    struct Network_MessageBody iov; System_Stack_zero(iov);
    iov.value = body;
    iov.length = System_UInt16_Max;

    struct Network_MessageHeader message; System_Stack_zero(message);
    message.content = &iov;
    message.contentCount = 1;
    message.flags = flags | Network_MessageFlags_WAITALL;

    System_ErrorCode errno = 0;
    System_Size reture = 0;
    while (1) {
        reture = System_Syscall_recvmsg(that->socketId, &message, flags);
        errno = System_Syscall_get_Error();
        if (errno) {
            if (errno == System_ErrorCode_EAGAIN) {
                System_Console_writeLine("Network_TCPSocket_receiveMessage Error: {0:string}, reture {1:uint}", 2, enum_getName(typeof(System_ErrorCode), errno), reture);
                continue;
            }
            break;
        }
        iov.length = reture;
        break;
    }
    if (errno) {
        System_Console_writeLine("Network_TCPSocket_receiveMessage Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
        return null;
    }
    if (reture) {
        System_String8 body1 = System_Memory_allocArray(typeof(System_Char8), reture);
        System_Memory_copyTo(iov.value, reture, body1);

        Network_MessageBody iov1 = System_Memory_allocArray(typeof(Network_MessageBody), Network_MessageHeader_ContentCapacity);
        iov1[0].value = body1;
        iov1[0].length = reture;

        Network_MessageHeader message1 = System_Memory_allocClass(typeof(Network_MessageHeader));
        message1->content = iov1;
        message1->contentCount = 1;
        message1->flags = message.flags;
        return message1;
    }
    return null;
}

void  base_Network_TCPSocket_sendMessage(Network_TCPSocket that, Network_MessageHeader message, Network_MessageFlags flags) {
    System_Syscall_sendmsg(that->socketId, message, flags);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_sendMessage Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

typedef struct Network_PollDescriptor {
    System_UInt32 socketId;
    Network_PollFlags inEvents;
    Network_PollFlags outEvents;
} * Network_PollDescriptor;

Network_PollFlags  base_Network_TCPSocket_poll(Network_TCPSocket that, Network_PollFlags request) {
    struct Network_PollDescriptor socketD = {
        .socketId = (System_UInt32)that->socketId,
        .inEvents = request,
        .outEvents = 0,
    };
    struct System_Syscall_timespec timeout = { .sec = 1, .nsec = 0 }; /* TODO */
    System_Size reture = System_Syscall_spoll(&socketD, 1, &timeout, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_poll Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
    return !reture ? 0 : socketD.outEvents;
}

struct System_Type Network_MessageBodyType = { .base = { .type = typeof(System_Type) }, 
    .name = "MessageBody", 
    .size = sizeof(struct Network_MessageBody),
};

struct System_Type Network_MessageHeaderType = { .base = { .type = typeof(System_Type) }, 
    .name = "MessageHeader", 
    .size = sizeof(struct  Network_MessageHeader),
};

struct System_Type Network_TCPSocketType = { .base = { .type = typeof(System_Type) }, 
    .name = "TCPSocket", 
    .size = sizeof(struct Network_TCPSocket),
    .baseType = typeof(System_Object),
};

#endif
