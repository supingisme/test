/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2014 Intel Corporation.
 * Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
 * All rights reserved.
 */

#ifndef _PARSE_ETHERADDR_H_
#define _PARSE_ETHERADDR_H_

#include <cmdline_parse.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTE_ETHER_ADDR_LEN 6
#define RTE_ETHER_ADDR_FMT_SIZE         18

struct rte_ether_addr {
		uint8_t addr_bytes[RTE_ETHER_ADDR_LEN]; /**< Addr bytes in tx order */
} __rte_aligned(2);

struct cmdline_token_etheraddr {
	struct cmdline_token_hdr hdr;
};
typedef struct cmdline_token_etheraddr cmdline_parse_token_etheraddr_t;

extern struct cmdline_token_ops cmdline_token_etheraddr_ops;

int cmdline_parse_etheraddr(cmdline_parse_token_hdr_t *tk, const char *srcbuf,
	void *res, unsigned ressize);
int cmdline_get_help_etheraddr(cmdline_parse_token_hdr_t *tk, char *dstbuf,
	unsigned int size);

#define TOKEN_ETHERADDR_INITIALIZER(structure, field)       \
{                                                           \
	/* hdr */                                               \
	{                                                       \
		&cmdline_token_etheraddr_ops,   /* ops */           \
		offsetof(structure, field),     /* offset */        \
	},                                                      \
}

#ifdef __cplusplus
}
#endif


#endif /* _PARSE_ETHERADDR_H_ */
