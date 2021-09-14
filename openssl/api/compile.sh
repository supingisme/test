# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. 
#!/bin/bash

gcc $* `pkg-config --libs --cflags openssl`
