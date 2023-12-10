/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_UInt32)
#include <min/System.Integers.auto.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_String)
#include <min/System.String.h>
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

struct System_Type Network_TCPSocketType = { .base = { .type = typeof(System_Type) },
    .name = "TCPSocket",
    .size = sizeof(struct Network_TCPSocket),
    .baseType = typeof(System_Object),
};

Network_TCPSocket  new_Network_TCPSocket() {
    Network_TCPSocket that = (Network_TCPSocket)System_Memory_allocClass(typeof(Network_TCPSocket));
    Network_TCPSocket_init(that);
    return that;
}

void  Network_TCPSocket_init(Network_TCPSocket that) {
    Network_TCPSocket_init__flags(that, 0);
}

Network_TCPSocket  new_Network_TCPSocket__flags(System_IntPtr flags) {
    Network_TCPSocket that = (Network_TCPSocket)System_Memory_allocClass(typeof(Network_TCPSocket));
    Network_TCPSocket_init__flags(that, flags);
    return that;
}

void  Network_TCPSocket_init__flags(Network_TCPSocket that, System_IntPtr flags) {

    that->socketId = System_Syscall_socket(Network_AddressFamily_IP4, Network_SocketType_STREAM | flags, 0);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_init Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void  Network_TCPSocket_close(Network_TCPSocket that) {
    if (!that->socketId) return;
    System_Syscall_close((System_Var)(System_IntPtr)that->socketId);
    that->socketId = null;
}

System_IntPtr  Network_TCPSocket_getSocketOption(Network_TCPSocket that, Network_SocketOption option) {
    System_IntPtr reture = 0;
    System_Size retureSize = sizeof(System_IntPtr);
    System_Syscall_getsockopt(that->socketId, Network_SocketLevel_SOCKET, option, &reture, &retureSize);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_getSocketOption Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
    return reture;
}

void  Network_TCPSocket_setSocketOption(Network_TCPSocket that, Network_SocketOption option, System_IntPtr value) {
    System_Syscall_setsockopt(that->socketId, Network_SocketLevel_SOCKET, option, &value, sizeof(System_IntPtr));
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_setSocketOption Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void  Network_TCPSocket_bind(Network_TCPSocket that, Network_IP4Address address, System_UInt16 port) {

    struct Network_SocketAddress socketAddress; System_Stack_clear(socketAddress);
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

void  Network_TCPSocket_listen(Network_TCPSocket that, System_Size backlog) {
    System_Syscall_listen(that->socketId, backlog);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_listen Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

Network_TCPSocket  Network_TCPSocket_accept(Network_TCPSocket that) {
    return Network_TCPSocket_accept__flags(that, 0);
}

Network_TCPSocket  Network_TCPSocket_accept__flags(Network_TCPSocket that, System_IntPtr flags) {
    /*struct Network_SocketAddress address; System_Stack_clear(address);
    System_Size addressLength = sizeof(struct Network_SocketAddress);*/
    Network_Socket_SID reture = System_Syscall_accept(that->socketId, null, 0, flags);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) {
        System_Console_writeLine("Network_TCPSocket_accept Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
        return null;
    }
    if (!reture) return null;
    Network_TCPSocket new = (Network_TCPSocket)System_Memory_allocClass(typeof(Network_TCPSocket));
    new->socketId = reture;
    return new;
}

System_String  Network_TCPSocket_receive(Network_TCPSocket that) {
    return Network_TCPSocket_receive__flags(that, 0);
}

System_String  Network_TCPSocket_receive__flags(Network_TCPSocket that, Network_MessageFlags flags) {

    System_Char8 body[System_UInt16_Max]; System_Stack_clear(body);
    System_Size length = stack_Network_TCPSocket_receive__flags(that, body, System_UInt16_Max, flags);
    if (!length) return null;
    System_String reture = System_Memory_allocClass(typeof(System_String));
    reture->length = length;
    reture->value = System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_Memory_copyTo(body, length, reture->value);
    return reture;
}

System_Size  stack_Network_TCPSocket_receive(Network_TCPSocket that, System_Char8 message[], System_Size length) {
    return stack_Network_TCPSocket_receive__flags(that, message, length, 0);
}

System_Size  stack_Network_TCPSocket_receive__flags(Network_TCPSocket that, System_Char8 message[], System_Size length, Network_MessageFlags flags) {

    System_ErrorCode errno = 0;
    System_Size reture = 0;
    while (true) {
        reture = System_Syscall_recv(that->socketId, message, length, flags);
        errno = System_Syscall_get_Error();
        if (errno) {
            if (errno == System_ErrorCode_EAGAIN) {
                System_Console_writeLine("Network_TCPSocket_receive Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
                continue;
            }
            System_Console_writeLine("Network_TCPSocket_receive Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
            return null;
        }
        return reture;
    }
}

void  Network_TCPSocket_send(Network_TCPSocket that, System_String message, Network_MessageFlags flags) {
    System_Syscall_send(that->socketId, message->value, message->length, flags);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_send Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

typedef struct Network_PollDescriptor {
    System_Int32 socketId;
    Network_PollFlags inEvents;
    Network_PollFlags outEvents;
} * Network_PollDescriptor;

Network_PollFlags  Network_TCPSocket_poll(Network_TCPSocket that, Network_PollFlags inFlags) {
    struct Network_PollDescriptor socketD = {
        .socketId = !that->socketId ? -1 : (System_Int32)that->socketId,
        .inEvents = inFlags,
        .outEvents = 0,
    };
    struct System_TimeSpan timeout = { .sec = 0, .usec = 0 }; /* TODO */
    System_Size reture = System_Syscall_ppoll(&socketD, 1, &timeout, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_poll Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
    return !reture ? 0 : socketD.outEvents;
}

System_Size  Network_TCPSocket_pollAny(Network_TCPSocket that[], System_Size count, Network_PollFlags inFlags, Network_PollFlags outFlags[]) {
    Debug_assert(that);
    Debug_assert(outFlags);
    if (count > 512) { Debug_assert(count <= 512); count = 512; }
    struct Network_PollDescriptor socketsD[512]; Stack_clear(socketsD);
    for (System_Size i = 0; i < count; ++i)
        if (!that[i] || !that[i]->socketId)
            socketsD[i].socketId = -1;
        else {
            socketsD[i].socketId = (System_Int32)that[i]->socketId;
            socketsD[i].inEvents = inFlags;
        }
    struct System_TimeSpan timeout = { .sec = 0, .usec = 0 }; /* TODO */
    System_Size reture = System_Syscall_ppoll(socketsD, count, &timeout, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("Network_TCPSocket_poll Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
    for (System_Size i = 0; i < count; ++i)
        if (!that[i] || !that[i]->socketId)
            outFlags[i] = 0;
        else
            outFlags[i] = socketsD[i].outEvents;
    return reture;
}

#endif
