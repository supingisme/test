/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2014 Intel Corporation.
 * Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
 * All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

#include "cmdline_common.h"
#include "cmdline_parse.h"
#include "cmdline_parse_etheraddr.h"

struct cmdline_token_ops cmdline_token_etheraddr_ops = {
	.parse = cmdline_parse_etheraddr,
	.complete_get_nb = NULL,
	.complete_get_elt = NULL,
	.get_help = cmdline_get_help_etheraddr,
};



void
rte_ether_format_addr(char *buf, uint16_t size,
		      const struct rte_ether_addr *eth_addr)
{
	snprintf(buf, size, "%02X:%02X:%02X:%02X:%02X:%02X",
		 eth_addr->addr_bytes[0],
		 eth_addr->addr_bytes[1],
		 eth_addr->addr_bytes[2],
		 eth_addr->addr_bytes[3],
		 eth_addr->addr_bytes[4],
		 eth_addr->addr_bytes[5]);
}

static int8_t get_xdigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	if (ch >= 'a' && ch <= 'f')
		return ch - 'a' + 10;
	if (ch >= 'A' && ch <= 'F')
		return ch - 'A' + 10;
	return -1;
}

/* Convert 00:11:22:33:44:55 to ethernet address */
static bool get_ether_addr6(const char *s0, struct rte_ether_addr *ea)
{
	const char *s = s0;
	int i;

	for (i = 0; i < RTE_ETHER_ADDR_LEN; i++) {
		int8_t x;

		x = get_xdigit(*s++);
		if (x < 0)
			return false;

		ea->addr_bytes[i] = x << 4;
		x = get_xdigit(*s++);
		if (x < 0)
			return false;
		ea->addr_bytes[i] |= x;

		if (i < RTE_ETHER_ADDR_LEN - 1 &&
		    *s++ != ':')
			return false;
	}

	/* return true if at end of string */
	return *s == '\0';
}

/* Convert 0011:2233:4455 to ethernet address */
static bool get_ether_addr3(const char *s, struct rte_ether_addr *ea)
{
	int i, j;

	for (i = 0; i < RTE_ETHER_ADDR_LEN; i += 2) {
		uint16_t w = 0;

		for (j = 0; j < 4; j++) {
			int8_t x;

			x = get_xdigit(*s++);
			if (x < 0)
				return false;
			w = (w << 4) | x;
		}
		ea->addr_bytes[i] = w >> 8;
		ea->addr_bytes[i + 1] = w & 0xff;

		if (i < RTE_ETHER_ADDR_LEN - 2 &&
		    *s++ != ':')
			return false;
	}

	return *s == '\0';
}

/*
 * Like ether_aton_r but can handle either
 * XX:XX:XX:XX:XX:XX or XXXX:XXXX:XXXX
 * and is more restrictive.
 */
int
rte_ether_unformat_addr(const char *s, struct rte_ether_addr *ea)
{
	if (get_ether_addr6(s, ea))
		return 0;
	if (get_ether_addr3(s, ea))
		return 0;

	errno = EINVAL;
	return -1;
}


int
cmdline_parse_etheraddr(__rte_unused cmdline_parse_token_hdr_t *tk,
	const char *buf, void *res, unsigned ressize)
{
	unsigned int token_len = 0;
	char ether_str[RTE_ETHER_ADDR_FMT_SIZE];
	struct rte_ether_addr tmp;

	if (res && ressize < sizeof(tmp))
		return -1;

	if (!buf || ! *buf)
		return -1;

	while (!cmdline_isendoftoken(buf[token_len]))
		token_len++;

	/* if token doesn't match possible string lengths... */
	if (token_len >= RTE_ETHER_ADDR_FMT_SIZE)
		return -1;

	strlcpy(ether_str, buf, token_len + 1);

	if (rte_ether_unformat_addr(ether_str, &tmp) < 0)
		return -1;

	if (res)
		memcpy(res, &tmp, sizeof(tmp));
	return token_len;
}

int
cmdline_get_help_etheraddr(__rte_unused cmdline_parse_token_hdr_t *tk,
			       char *dstbuf, unsigned int size)
{
	int ret;

	ret = snprintf(dstbuf, size, "Ethernet address");
	if (ret < 0)
		return -1;
	return 0;
}
