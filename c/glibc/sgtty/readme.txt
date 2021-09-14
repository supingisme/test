# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. 
17.5 BSD Terminal Modes
The usual way to get and set terminal modes is with the functions described in Section 17.4
[Terminal Modes], page 435. However, on some systems you can use the BSD-derived
functions in this section to do some of the same thing. On many systems, these functions
do not exist. Even with the GNU C library, the functions simply fail with errno = ENOSYS
with many kernels, including Linux.
The symbols used in this section are declared in gtty.hb17.5 BSD Terminal Modes
The usual way to get and set terminal modes is with the functions described in Section 17.4
[Terminal Modes], page 435. However, on some systems you can use the BSD-derived
functions in this section to do some of the same thing. On many systems, these functions
do not exist. Even with the GNU C library, the functions simply fail with errno = ENOSYS
with many kernels, including Linux.
The symbols used in this section are declared in gtty.hb17.5 BSD Terminal Modes
The usual way to get and set terminal modes is with the functions described in Section 17.4
[Terminal Modes], page 435. However, on some systems you can use the BSD-derived
functions in this section to do some of the same thing. On many systems, these functions
do not exist. Even with the GNU C library, the functions simply fail with errno = ENOSYS
with many kernels, including Linux.
The symbols used in this section are declared in "sgtty.h"

#include <sgtty.h>
