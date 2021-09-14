# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:41 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:50 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. 
#!/bin/bash

#!/bin/bash
# script to filter out bad phone numbers
echo $1 | gawk --re-interval '/^\(?[2-9][0-9]{2}\)?(| |-|\[0-9]{3}( |-|\.)[0-9]{4}/{print $0}'
