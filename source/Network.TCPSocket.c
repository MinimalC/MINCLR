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

    struct Network_SocketAddress socketAddress = {
        .family = Network_AddressFamily_IP4,
        .port = System_UInt16_toNetworkOrder(port),
    };
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
    struct Network_SocketAddress address;
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

struct System_Type Network_TCPSocketType = { .base = stack_System_Object(System_Type), 
    .name = "TCPSocket", 
    .size = sizeof(struct Network_TCPSocket),
    .baseType = typeof(System_Object),
};

#endif
