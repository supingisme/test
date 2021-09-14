/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 14:07:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 11:02:48 CST. */
#ifndef _STATE_H
#define _STATE_H


enum root_state_t {
ROOT_STATE_MIN,
ROOT_STATE_VIRT_CELL,
ROOT_STATE_SIMU_CELL,
ROOT_STATE_NON_INTEGRATE_CELL,
ROOT_STATE_MAX,
ROOT_STATE_NULL,
};

enum cell_state_t {
CELL_STATE_MIN,
CELL_STATE_SETUP,
CELL_STATE_MIGRATION,
CELL_STATE_EXPAND,
CELL_STATE_REDUCE,
CELL_STATE_NORMAL,
CELL_STATE_DELETE,
CELL_STATE_MAX,
CELL_STATE_NULL, /* to deal with no state situation, not for cell isn't setuping */
};

enum cfg_state_t {
CFG_STATE_MIN,
CFG_STATE_RRU_CFG,
CFG_STATE_PHY_CFG,
CFG_STATE_MAC_CFG,
CFG_STATE_MAX,
CFG_STATE_NULL,
};

#endif /*<_STATE_H>*/
