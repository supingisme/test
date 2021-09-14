/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 14:07:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 11:02:48 CST. */
#ifndef _EVENT_H
#define _EVENT_H

enum event_t {
SM_EVENT_MIN,
SM_EVENT_CELL_SETUP_REQ,
SM_EVENT_CELL_DELETE_REQ,
SM_EVENT_RRU_CFG_RSP,
SM_EVENT_PHY_CFG_RSP,
SM_EVENT_MAC_CFG_RSP,
SM_EVENT_MAX,
SM_EVENT_NULL,
};


typedef struct Event {
	int event;
	struct Event *subevent;
}Event_t;


#endif /*<_EVENT_H>*/
