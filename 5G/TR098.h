/**
 *  TR-098: Internet Gateway Device Data Model for TR-069
 *      Rong Tao 
 */
#ifndef __TR098_H
#define __TR098_H 1


/* A.2 Table 1 – Default Layer 2/3 QoS Mapping */
enum TR098_tab1 {
	BK		= 001,//1
	//spare	= 010,//2
	BE		= 000,//0
	EE		= 011,//3
	CL		= 0100,//4
	VI		= 0101,//5
	VO		= 0110,
	NC		= 0111,
	CS0		= 0x00,
	AF13	= 0x0e,
	AF12	= 0x0c,
	AF11	= 0x0a,
	CS1		= 0x08,
	AF23	= 0x16,
	AF22	= 0x14,
	AF21	= 0x12,
	CS2		= 0x10,
	AF33	= 0x1e,
	AF32	= 0x1c,
	AF31	= 0x1a,
	CS3		= 0x18,
	AF43	= 0x26,
	AF42	= 0x24,
	AF41	= 0x22,
	CS4		= 0x20,
	EF      = 0x2e,
	CS5     = 0x28,
	CS6     = 0x30,
	CS7     = 0x38,
};


/* A.3.1 Table 2 – ProtocolIdentifer URNs 统一资源名称 (Uniform Resource Name, URN)，*/
/*
URN                     Description
urn:dslforum-org:sip    Session Initiaion Protocol (SIP) as defined by RFC [7]
urn:dslforum-org:h.323  ITU-T Recommendation H.323
urn:dslforum-org:h.248  ITU-T Recommendation H.248 (MEGACO)
urn:dslforum-org:mgcp   Media Gateway Control Protocol (MGCP) as defined by RFC 3435 [8]
urn:dslforum-org:pppoe  Bridged sessions of PPPoE
*/



#endif /*<__TR098_H>*/
