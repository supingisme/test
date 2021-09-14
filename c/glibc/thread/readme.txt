# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:33 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:06 CST. 


We #include <thread.h>, in addition to the normal <pthread.h>, because we need to use Solaris threads in addition to Pthreads, as we will describe shortly.

We have added one member to the file structure: f_tid, the thread ID. The remainder of this code is similar to Figure 16.15(See 9.5.5). With this threads version, we do not use select and therefore do not need any descriptor sets or the variable maxfd.


