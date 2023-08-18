/* Gemeinfrei. Public Domain. */
#include "../System.internal.h"
#include <min/System.h>

IntPtr WebService_serve(Size argc, Var argv[]) {
    if (argc < 1) return false;
    Network_TCPSocket tcp = argv[0];

    return true;
}

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 1) {
        System_Console_writeLine__string("Usage: WebService <command> <file>");
        return false;
    }

    Network_TCPSocket tcp = Network_TCPSocket_create();
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_REUSEADDR, true);
    base_Network_TCPSocket_setSocketOption(tcp, Network_SocketOption_REUSEPORT, true);

    Network_IP4Address ip4 = { .address32 = inline_System_UInt32_toNetworkOrder(0x7F000001) }; // { 127, 0, 0, 1 }
    System_UInt16 port = 8081;
    base_Network_TCPSocket_bind(tcp, ip4, port);
    System_Console_writeLine("WebService Network_IP4Address: {0:uint8}.{1:uint8}.{2:uint8}.{3:uint8}:{4:uint16}", 5, 
        ip4.address[0], ip4.address[1], ip4.address[2], ip4.address[3], port);

    base_Network_TCPSocket_listen(tcp, 512);

    Network_TCPSocket sockets[512];
    System_Thread threads[512];

    while (true) {
     
        Network_TCPSocket tcp1 = base_Network_TCPSocket_accept(tcp);
        
        System_Thread thread1 = System_Thread_create(WebService_serve, 1, tcp1);


        for (Size i = 0; i < 512; ++i) {
            if (!sockets[i] && !threads[i]) {
                sockets[i] = tcp1;
                threads[i] = thread1;
            }
        }

        break;
    }
    return false;
}
