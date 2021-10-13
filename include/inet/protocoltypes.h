/* Standard well-defined IP protocols.  */
enum
  {
    IPPROTO_IP = 0,	   /* Dummy protocol for TCP.  */
#define IPPROTO_IP		IPPROTO_IP
    IPPROTO_ICMP = 1,	   /* Internet Control Message Protocol.  */
#define IPPROTO_ICMP		IPPROTO_ICMP
    IPPROTO_IGMP = 2,	   /* Internet Group Management Protocol. */
#define IPPROTO_IGMP		IPPROTO_IGMP
    IPPROTO_IPIP = 4,	   /* IPIP tunnels (older KA9Q tunnels use 94).  */
#define IPPROTO_IPIP		IPPROTO_IPIP
    IPPROTO_TCP = 6,	   /* Transmission Control Protocol.  */
#define IPPROTO_TCP		IPPROTO_TCP
    IPPROTO_EGP = 8,	   /* Exterior Gateway Protocol.  */
#define IPPROTO_EGP		IPPROTO_EGP
    IPPROTO_PUP = 12,	   /* PUP protocol.  */
#define IPPROTO_PUP		IPPROTO_PUP
    IPPROTO_UDP = 17,	   /* User Datagram Protocol.  */
#define IPPROTO_UDP		IPPROTO_UDP
    IPPROTO_IDP = 22,	   /* XNS IDP protocol.  */
#define IPPROTO_IDP		IPPROTO_IDP
    IPPROTO_TP = 29,	   /* SO Transport Protocol Class 4.  */
#define IPPROTO_TP		IPPROTO_TP
    IPPROTO_DCCP = 33,	   /* Datagram Congestion Control Protocol.  */
#define IPPROTO_DCCP		IPPROTO_DCCP
    IPPROTO_IPV6 = 41,     /* IPv6 header.  */
#define IPPROTO_IPV6		IPPROTO_IPV6
    IPPROTO_RSVP = 46,	   /* Reservation Protocol.  */
#define IPPROTO_RSVP		IPPROTO_RSVP
    IPPROTO_GRE = 47,	   /* General Routing Encapsulation.  */
#define IPPROTO_GRE		IPPROTO_GRE
    IPPROTO_ESP = 50,      /* encapsulating security payload.  */
#define IPPROTO_ESP		IPPROTO_ESP
    IPPROTO_AH = 51,       /* authentication header.  */
#define IPPROTO_AH		IPPROTO_AH
    IPPROTO_MTP = 92,	   /* Multicast Transport Protocol.  */
#define IPPROTO_MTP		IPPROTO_MTP
    IPPROTO_BEETPH = 94,   /* IP option pseudo header for BEET.  */
#define IPPROTO_BEETPH		IPPROTO_BEETPH
    IPPROTO_ENCAP = 98,	   /* Encapsulation Header.  */
#define IPPROTO_ENCAP		IPPROTO_ENCAP
    IPPROTO_PIM = 103,	   /* Protocol Independent Multicast.  */
#define IPPROTO_PIM		IPPROTO_PIM
    IPPROTO_COMP = 108,	   /* Compression Header Protocol.  */
#define IPPROTO_COMP		IPPROTO_COMP
    IPPROTO_SCTP = 132,	   /* Stream Control Transmission Protocol.  */
#define IPPROTO_SCTP		IPPROTO_SCTP
    IPPROTO_UDPLITE = 136, /* UDP-Lite protocol.  */
#define IPPROTO_UDPLITE		IPPROTO_UDPLITE
    IPPROTO_MPLS = 137,    /* MPLS in IP.  */
#define IPPROTO_MPLS		IPPROTO_MPLS
    IPPROTO_RAW = 255,	   /* Raw IP packets.  */
#define IPPROTO_RAW		IPPROTO_RAW
    IPPROTO_MAX
  };

/* Bits in the FLAGS argument to `send', `recv', et al.  */
enum
  {
    MSG_OOB		= 0x01,	/* Process out-of-band data.  */
#define MSG_OOB		MSG_OOB
    MSG_PEEK		= 0x02,	/* Peek at incoming messages.  */
#define MSG_PEEK	MSG_PEEK
    MSG_DONTROUTE	= 0x04,	/* Don't use local routing.  */
#define MSG_DONTROUTE	MSG_DONTROUTE
#ifdef __USE_GNU
    /* DECnet uses a different name.  */
    MSG_TRYHARD		= MSG_DONTROUTE,
# define MSG_TRYHARD	MSG_DONTROUTE
#endif
    MSG_CTRUNC		= 0x08,	/* Control data lost before delivery.  */
#define MSG_CTRUNC	MSG_CTRUNC
    MSG_PROXY		= 0x10,	/* Supply or ask second address.  */
#define MSG_PROXY	MSG_PROXY
    MSG_TRUNC		= 0x20,
#define MSG_TRUNC	MSG_TRUNC
    MSG_DONTWAIT	= 0x40, /* Nonblocking IO.  */
#define MSG_DONTWAIT	MSG_DONTWAIT
    MSG_EOR		= 0x80, /* End of record.  */
#define MSG_EOR		MSG_EOR
    MSG_WAITALL		= 0x100, /* Wait for a full request.  */
#define MSG_WAITALL	MSG_WAITALL
    MSG_FIN		= 0x200,
#define MSG_FIN		MSG_FIN
    MSG_SYN		= 0x400,
#define MSG_SYN		MSG_SYN
    MSG_CONFIRM		= 0x800, /* Confirm path validity.  */
#define MSG_CONFIRM	MSG_CONFIRM
    MSG_RST		= 0x1000,
#define MSG_RST		MSG_RST
    MSG_ERRQUEUE	= 0x2000, /* Fetch message from error queue.  */
#define MSG_ERRQUEUE	MSG_ERRQUEUE
    MSG_NOSIGNAL	= 0x4000, /* Do not generate SIGPIPE.  */
#define MSG_NOSIGNAL	MSG_NOSIGNAL
    MSG_MORE		= 0x8000,  /* Sender will send more.  */
#define MSG_MORE	MSG_MORE
    MSG_WAITFORONE	= 0x10000, /* Wait for at least one packet to return.*/
#define MSG_WAITFORONE	MSG_WAITFORONE
    MSG_BATCH		= 0x40000, /* sendmmsg: more messages coming.  */
#define MSG_BATCH	MSG_BATCH
    MSG_ZEROCOPY	= 0x4000000, /* Use user data in kernel path.  */
#define MSG_ZEROCOPY	MSG_ZEROCOPY
    MSG_FASTOPEN	= 0x20000000, /* Send data in TCP SYN.  */
#define MSG_FASTOPEN	MSG_FASTOPEN

    MSG_CMSG_CLOEXEC	= 0x40000000	/* Set close_on_exit for file
					   descriptor received through
					   SCM_RIGHTS.  */
#define MSG_CMSG_CLOEXEC MSG_CMSG_CLOEXEC
  };