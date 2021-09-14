# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 26日 星期三 08:58:16 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 21日 星期五 08:57:16 CST. 


gcc -shared -fPIC -o libtest.so test1.o test2.o

gcc -static -o app app.o -L. –ltest
