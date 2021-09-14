# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:50 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash
#
# Hourly_Archive - Every hour create an archive
#########################################################
#
# Set Configuration File
#
CONFIG_FILE=/archive/hourly/Files_To_Backup
#
# Set Base Archive Destination Location
#
BASEDEST=/archive/hourly
#
# Gather Current Day, Month & Time
#
DAY=$(date +%d)
	MONTH=$(date +%m)
	TIME=$(date +%k%M)
#
# Create Archive Destination Directory
#
	mkdir -p $BASEDEST/$MONTH/$DAY
#
# Build Archive Destination File Name
#
	DESTINATION=$BASEDEST/$MONTH/$DAY/archive$TIME.tar.gz
#
########## Main Script ####################
