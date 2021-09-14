/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:18 CST. */


struct icmp6_filter
{
	uint32_t icmp6_filt[8];
};

struct icmp6_hdr
{
	uint8_t     icmp6_type;   /* type field */
	uint8_t     icmp6_code;   /* code field */
	uint16_t    icmp6_cksum;  /* checksum field */
	union
	{
		uint32_t  icmp6_un_data32[1]; /* type-specific field */
		uint16_t  icmp6_un_data16[2]; /* type-specific field */
		uint8_t   icmp6_un_data8[4];  /* type-specific field */
	} icmp6_dataun;
};


/**
 * Format of ICMPv4 and ICMPv6 messages.
 *
 * 0                7 8               15 16                                        31
 * +-----------------+------------------+------------------------------------------+
 * |      type       |       code       |           checksum                       |
 * +-----------------+------------------+------------------------------------------+
 * |                                                                               |
 * ..                 (remainder depends on type and code )                       ...
 * |                   and whether ICMPv4 or ICMPv6)                               |
 * +-------------------------------------------------------------------------------+
 *
 *
 */
