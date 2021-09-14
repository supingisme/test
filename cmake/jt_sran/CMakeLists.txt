# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:45 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 16:15:03 CST. 
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(jt_sran)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

aux_source_directory(product_om/cell_mgmt/src DIR_SRCS)
aux_source_directory(product_om/inet_mgmt/src DIR_SRCS)
aux_source_directory(product_om/perf_mgmt/src DIR_SRCS)
aux_source_directory(product_om/ DIR_SRCS)

include_directories(product_om/cell_mgmt/include)
include_directories(product_om/inet_mgmt/include)
include_directories(product_om/perf_mgmt/include)
include_directories(vos/include)

include_directories(/usr/include/libxml2)

find_library(CONFIG config /usr/lib64)
find_library(MYSQLCLIENT mysqlclient /usr/lib64/mysql)
find_library(NETSNMP netsnmp /usr/lib64)
find_library(PTHREAD pthread /usr/lib64)
find_library(GROS gros vos/)
find_library(XML2 xml2 /usr/lib64)
find_library(RT rt /usr/lib64)

link_libraries(${CONFIG} ${MYSQLCLIENT} ${NETSNMP} ${GROS} ${PTHREAD} ${XML2} ${RT})
#target_link_libraries(jt_sran gros)

add_definitions(-MD -Wall -DOS_LINUX -pthread)

ADD_EXECUTABLE(jt_sran ${SRC_LIST} ${DIR_SRCS})

