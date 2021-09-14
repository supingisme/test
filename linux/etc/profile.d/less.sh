# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:26 CST. 
# less initialization script (sh)
[ -x /usr/bin/lesspipe.sh ] && export LESSOPEN="${LESSOPEN-||/usr/bin/lesspipe.sh %s}"
