/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 14:07:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 11:02:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:12 CST. 
*/
#include <stdio.h>
#include "sm.h"
#include "state.h"
#include "event.h"

#define debug() printf("%s:%d\n", __func__, __LINE__)
#define F(fname) int fname(int id, void *arg){debug();}

F(f1);
F(f2);
F(f3);
F(f4);
F(f5);
F(f6);
F(f7);

struct sm_node_t sm[] = 
{
	{0, CELL_STATE_SETUP, CFG_STATE_RRU_CFG, SM_EVENT_RRU_CFG_RSP, f1},
	{0, CELL_STATE_SETUP, CFG_STATE_PHY_CFG, SM_EVENT_PHY_CFG_RSP, f2},
	{0, CELL_STATE_SETUP, CFG_STATE_MAC_CFG, SM_EVENT_MAC_CFG_RSP, f3},
	{0, CELL_STATE_DELETE, CFG_STATE_RRU_CFG, SM_EVENT_RRU_CFG_RSP, f4},
	{0, CELL_STATE_DELETE, CFG_STATE_PHY_CFG, SM_EVENT_PHY_CFG_RSP, f5},
	{0, CELL_STATE_DELETE, CFG_STATE_PHY_CFG, SM_EVENT_MAC_CFG_RSP, f6},
	{0, CELL_STATE_NORMAL, CFG_STATE_NULL, SM_EVENT_NULL, f7},
};

int cmp_sm_hdr(void *l, void *r)
{
	return memcmp(l, r, sizeof(struct sm_hdr_t));
}

int do_sm(enum cell_state_t s0, enum cell_state_t s1, enum cfg_state_t s2, enum event_t e, int id)
{
	struct sm_hdr_t hdr = {s0, s1, s2, e};

	struct sm_node_t *node = NULL;
	node = (struct sm_node_t *)bsearch(&hdr, sm, 
										sizeof(sm)/sizeof(struct sm_node_t), 
										sizeof(struct sm_node_t),
										&cmp_sm_hdr);

	(node->handler)(id, NULL);

}

int main(int argc, char *argv[])
{	
	(sm[1].handler)(1, NULL);

	do_sm(0,CELL_STATE_DELETE,CFG_STATE_RRU_CFG,SM_EVENT_RRU_CFG_RSP,1);

	

	return 0;
}

