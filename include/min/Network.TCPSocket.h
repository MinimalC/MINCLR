/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_Network_TCPSocket)
#define have_Network_TCPSocket

typedef System_UInt16 Network_AddressFamily;
enum {
    Network_AddressFamily_UNSPECIFIED,      /* Unspecified.  */
    Network_AddressFamily_LOCAL = 1,        /* Local to host (pipes and file-domain).  */
    Network_AddressFamily_UNIX = Network_AddressFamily_LOCAL, /* Old BSD name for PF_LOCAL.  */
    Network_AddressFamily_IP4 = 2,          /* IP protocol family.  */
    Network_AddressFamily_AX25 = 3,         /* Amateur Radio AX.25.  */
    Network_AddressFamily_IPX = 4,          /* Novell Internet Protocol.  */
    Network_AddressFamily_APPLETALK = 5,    /* Appletalk DDP.  */
    Network_AddressFamily_NETROM = 6,       /* Amateur radio NetROM.  */
    Network_AddressFamily_BRIDGE = 7,       /* Multiprotocol bridge.  */
    Network_AddressFamily_ATMPVC = 8,       /* ATM PVCs.  */
    Network_AddressFamily_X25 = 9,          /* Reserved for X.25 project.  */
    Network_AddressFamily_IP6 = 10,         /* IP version 6.  */
    Network_AddressFamily_ROSE = 11,        /* Amateur Radio X.25 PLP.  */
    Network_AddressFamily_DECnet = 12,      /* Reserved for DECnet project.  */
    Network_AddressFamily_NETBEUI = 13,     /* Reserved for 802.2LLC project.  */
    Network_AddressFamily_SECURITY = 14,    /* Security callback pseudo AF.  */
    Network_AddressFamily_KEY = 15,         /* Key management API.  */
    Network_AddressFamily_NETLINK = 16,
    Network_AddressFamily_ROUTE = Network_AddressFamily_NETLINK, /* Alias to emulate 4.4BSD.  */
    Network_AddressFamily_PACKET = 17,      /* Packet family.  */
    Network_AddressFamily_ASH = 18,         /* Ash.  */
    Network_AddressFamily_ECONET = 19,      /* Acorn Econet.  */
    Network_AddressFamily_ATMSVC = 20,      /* ATM SVCs.  */
    Network_AddressFamily_RDS = 21,         /* RDS sockets.  */
    Network_AddressFamily_SNA = 22,         /* Linux SNA Project */
    Network_AddressFamily_IRDA = 23,        /* IRDA sockets.  */
    Network_AddressFamily_PPPOX = 24,       /* PPPoX sockets.  */
    Network_AddressFamily_WANPIPE = 25,     /* Wanpipe API sockets.  */
    Network_AddressFamily_LLC = 26,         /* Linux LLC.  */
    Network_AddressFamily_CAN = 29,         /* Controller Area Network.  */
    Network_AddressFamily_TIPC = 30,        /* TIPC sockets.  */
    Network_AddressFamily_BLUETOOTH = 31,   /* Bluetooth sockets.  */
    Network_AddressFamily_IUCV = 32,        /* IUCV sockets.  */
    Network_AddressFamily_RXRPC = 33,       /* RxRPC sockets.  */
    Network_AddressFamily_ISDN = 34,        /* mISDN sockets.  */
    Network_AddressFamily_PHONET = 35,      /* Phonet sockets.  */
    Network_AddressFamily_IEEE802154 = 36,  /* IEEE 802.15.4 sockets.  */
    Network_AddressFamily_CAIF = 37,        /* CAIF sockets.  */
    Network_AddressFamily_ALG = 38,         /* Algorithm sockets.  */
    Network_AddressFamily_NFC = 39,         /* NFC sockets.  */
};

typedef System_IntPtr Network_SocketType;
enum {
  Network_SocketType_STREAM = 1,    /* Sequenced, reliable, connection-based byte streams.  */
  Network_SocketType_DATAGRAM = 2,  /* Connectionless, unreliable datagrams of fixed maximum length.  */
  Network_SocketType_RAW = 3,       /* Raw protocol interface.  */
  Network_SocketType_RDM = 4,       /* Reliably-delivered messages.  */
  Network_SocketType_SEQPACKET = 5, /* Sequenced, reliable, connection-based, datagrams of fixed maximum length.  */
  Network_SocketType_DCCP = 6,      /* Datagram Congestion Control Protocol.  */
  Network_SocketType_PACKET = 10,   /* Linux specific way of getting packets at the dev level.  For writing rarp and other similar things on the user level. */

  /* Flags to be ORed into the type parameter of socket and socketpair.  */
  Network_SocketType_CLOSEONEXEC = 0x02000000,    /* Atomically set close-on-exec flag for the new descriptor(s).  */
  Network_SocketType_NONBLOCK = 0x00004000,       /* Atomically mark descriptor(s) as non-blocking.  */
};

typedef System_IntPtr Network_IPProtocol;
enum {
    Network_IPProtocol_HOPOPTS = 0,     /* IPv6 Hop-by-Hop options.  */
    Network_IPProtocol_ICMP = 1,        /* Internet Control Message Protocol.  */
    Network_IPProtocol_IGMP = 2,        /* Internet Group Management Protocol. */
    Network_IPProtocol_IPIP = 4,        /* IPIP tunnels (older KA9Q tunnels use 94).  */
    Network_IPProtocol_TCP = 6,         /* Transmission Control Protocol.  */
    Network_IPProtocol_EGP = 8,         /* Exterior Gateway Protocol.  */
    Network_IPProtocol_PUP = 12,        /* PUP protocol.  */
    Network_IPProtocol_UDP = 17,        /* User Datagram Protocol.  */
    Network_IPProtocol_IDP = 22,        /* XNS IDP protocol.  */
    Network_IPProtocol_TP = 29,         /* SO Transport Protocol Class 4.  */
    Network_IPProtocol_DCCP = 33,       /* Datagram Congestion Control Protocol.  */
    Network_IPProtocol_IPV6 = 41,       /* IPv6 header.  */
    Network_IPProtocol_ROUTING = 43,    /* IPv6 routing header.  */
    Network_IPProtocol_FRAGMENT = 44,   /* IPv6 fragmentation header.  */
    Network_IPProtocol_RSVP = 46,       /* Reservation Protocol.  */
    Network_IPProtocol_GRE = 47,        /* General Routing Encapsulation.  */
    Network_IPProtocol_ESP = 50,        /* encapsulating security payload.  */
    Network_IPProtocol_AH = 51,         /* authentication header.  */
    Network_IPProtocol_ICMPV6 = 58,     /* ICMPv6.  */
    Network_IPProtocol_NONE = 59,       /* IPv6 no next header.  */
    Network_IPProtocol_DSTOPTS = 60,    /* IPv6 destination options.  */
    Network_IPProtocol_MTP = 92,        /* Multicast Transport Protocol.  */
    Network_IPProtocol_ENCAP = 98,      /* Encapsulation Header.  */
    Network_IPProtocol_PIM = 103,       /* Protocol Independent Multicast.  */
    Network_IPProtocol_COMP = 108,      /* Compression Header Protocol.  */
    Network_IPProtocol_SCTP = 132,      /* Stream Control Transmission Protocol.  */
    Network_IPProtocol_UDPLITE = 136,   /* UDP-Lite protocol.  */
    Network_IPProtocol_RAW = 255,       /* Raw IP packets.  */
};

typedef System_IntPtr Network_SocketLevel;
enum {
    Network_SocketLevel_SOCKET = 1,
};

typedef System_IntPtr Network_SocketOption;
enum {
    Network_SocketOption_DEBUG = 1,
    Network_SocketOption_REUSEADDR = 2,
    Network_SocketOption_TYPE = 3,
    Network_SocketOption_ERROR = 4,
    Network_SocketOption_DONTROUTE = 5,
    Network_SocketOption_BROADCAST = 6,
    Network_SocketOption_SNDBUF = 7,
    Network_SocketOption_RCVBUF = 8,
    Network_SocketOption_SNDBUFFORCE = 32,
    Network_SocketOption_RCVBUFFORCE = 33,
    Network_SocketOption_KEEPALIVE = 9,
    Network_SocketOption_OOBINLINE = 10,
    Network_SocketOption_NO_CHECK = 11,
    Network_SocketOption_PRIORITY = 12,
    Network_SocketOption_LINGER = 13,
    Network_SocketOption_BSDCOMPAT = 14,
    Network_SocketOption_REUSEPORT = 15,
};

typedef struct Network_IP4Address {
    System_UInt8 address[4];
} Network_IP4Address;

typedef struct Network_IP6Address {
    System_UInt8 address[16];
} Network_IP6Address;

typedef struct Network_SocketAddress {

    Network_AddressFamily family;

    System_UInt16 port;

    System_UInt8 address[16];

}  * Network_SocketAddress;

typedef System_IntPtr Network_TCPSocket_Status;

typedef System_fixed struct Network_TCPSocket {
    struct System_Object base;

    System_IntPtr socketId;

    Network_TCPSocket_Status status;

}  * Network_TCPSocket;

export struct System_Type  Network_TCPSocketType;

export Network_TCPSocket  Network_TCPSocket_create();

export System_IntPtr  base_Network_TCPSocket_getSocketOption(Network_TCPSocket that, Network_SocketOption option);
export void  base_Network_TCPSocket_setSocketOption(Network_TCPSocket that, Network_SocketOption option, System_IntPtr value);

export void  base_Network_TCPSocket_bind(Network_TCPSocket that, Network_IP4Address address, System_UInt16 port);
export void  base_Network_TCPSocket_listen(Network_TCPSocket that, System_Size backlog);
export Network_TCPSocket  base_Network_TCPSocket_accept(Network_TCPSocket that);
export Network_TCPSocket  base_Network_TCPSocket_accept__flags(Network_TCPSocket that, System_IntPtr flags);

#endif
