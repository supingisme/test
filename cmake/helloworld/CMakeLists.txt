# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:44 CST. 

#cmake lowest version dependens, 
#if don't include the following scentence, there is a warning
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#project name
PROJECT(hello)

#add current directory(./)'s all source code to var SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)

aux_source_directory(src DIR_SRCS)
aux_source_directory(vos DIR_SRCS)

include_directories(src)
include_directories(vos)

find_library(CONFIG config /usr/lib64)
find_library(MYSQLCLIENT mysqlclient /usr/lib64/mysql)
find_library(NETSNMP netsnmp /usr/lib64)
link_libraries(${CONFIG} ${MYSQLCLIENT} ${NETSNMP})

add_definitions( -MD -Wall -DOS_LINUX)

#generate application hello 
ADD_EXECUTABLE(hello ${SRC_LIST} ${DIR_SRCS})

