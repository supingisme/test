CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(OM_5G)

# Add your source folder in here
aux_source_directory(jtsran5G DIR_SRCS)
aux_source_directory(jtsran5G/common DIR_SRCS)
aux_source_directory(jtsran5G/CPE/om_du DIR_SRCS)
aux_source_directory(jtsran5G/om_cucp/src DIR_SRCS)
aux_source_directory(jtsran5G/om_cuup/src DIR_SRCS)
aux_source_directory(jtsran5G/om_du/src DIR_SRCS)
aux_source_directory(jtsran5G/om_perf/src DIR_SRCS)
aux_source_directory(jtsran5G/om_inet/src DIR_SRCS)
aux_source_directory(jtsran5G/om_tools/src DIR_SRCS)
aux_source_directory(jtsran5G/protos DIR_SRCS)
aux_source_directory(jtsran5G/MIB DIR_SRCS)
aux_source_directory(jtsran5G/MIB/board_mib/src DIR_SRCS)
aux_source_directory(jtsran5G/MIB/omdu_mib/src DIR_SRCS)
aux_source_directory(jtsran5G/MIB/cucp_mib/src DIR_SRCS)
aux_source_directory(jtsran5G/MIB/cuup_mib/src DIR_SRCS)
aux_source_directory(jtsran5G/MIB/rru_mib/src DIR_SRCS)
aux_source_directory(jtsran5G/MIB/main_ctrl DIR_SRCS)
aux_source_directory(jtsran5G/main_ctrl/src DIR_SRCS)
aux_source_directory(jtsran5G/ftp/src DIR_SRCS)
aux_source_directory(jtsran5G/bord_mgmt/src DIR_SRCS)
aux_source_directory(jtsran5G/trap_module DIR_SRCS)
aux_source_directory(jtsran5G/adaptor/acc/src DIR_SRCS)
aux_source_directory(jtsran5G/adaptor/acc/ACC/src DIR_SRCS)
aux_source_directory(common_lib/src DIR_SRCS)
aux_source_directory(product/src DIR_SRCS)
aux_source_directory(jtsran5G/upgrade_mgmt/src DIR_SRCS)
aux_source_directory(jtsran5G/om_rrum/src DIR_SRCS)
aux_source_directory(jtsran5G/netconf/src DIR_SRCS)

aux_source_directory(./ DIR_SRCS)

# Add your header folder in here
include_directories(
	jtsran5G/adaptor/acc/include
	jtsran5G/adaptor/acc/ACC/include
    jtsran5G/common
    jtsran5G/CPE/om_du
    jtsran5G/om_cucp/include
    jtsran5G/om_cuup/include
    jtsran5G/om_du/include
    jtsran5G/om_perf/include
    jtsran5G/om_inet/include
    jtsran5G/om_tools/include
    jtsran5G/protos/
    jtsran5G/MIB
    jtsran5G/MIB/main_ctrl
    jtsran5G/MIB/board_mib/H
    jtsran5G/MIB/omdu_mib/include
    jtsran5G/MIB/cucp_mib/include
    jtsran5G/MIB/cuup_mib/include
    jtsran5G/MIB/rru_mib/include
    jtsran5G/main_ctrl/include
    jtsran5G/ftp/include
    jtsran5G/bord_mgmt/h
    jtsran5G/trap_module
    jtsran5G/upgrade_mgmt/include
    platform/include
    product/include
    common_lib/include
    /usr/include/libxml2
    debug/test_file/ACC/include
    jtsran5G/om_rrum/include
    jtsran5G/netconf/include
)

# All library the "jt_sran" needed
find_library(CONFIG config /usr/lib64)
# find_library(MYSQLCLIENT mysqlclient /usr/lib64/mysql)
find_library(NETSNMP netsnmp /usr/lib64)
find_library(NETSNMPMIBS netsnmpmibs /usr/lib64)
find_library(NETSNMPAGENT netsnmpagent /usr/lib64)
find_library(PTHREAD pthread /usr/lib64)
find_library(GROS gros platform/target_libs/)
find_library(XML2 xml2 /usr/lib64)
find_library(RT rt /usr/lib64)
find_library(DL dl /usr/lib64)
find_library(MATH m /usr/lib64)
find_library(YANG yang /usr/local/lib)
find_library(NETCONF2 netconf2 /usr/local/lib64)
find_library(JSONC json-c /usr/lib64)
find_library(UCI uci /usr/local/lib/)
find_library(UBOX ubox /usr/local/lib/)
find_library(UBUS ubus /usr/local/lib/)
find_library(CURL curl /usr/local/lib/)
find_library(MICROXML microxml /usr/lib64)

# Link library
link_libraries( ${DL} ${NETSNMP} ${GROS} ${YANG} ${NETCONF2}
		${NETSNMPMIBS} ${NETSNMPAGENT} ${PTHREAD} ${XML2} ${RT} ${MATH} ${CONFIG} ${JSONC} ${UCI} ${UBOX} ${UBUS} ${CURL} ${MICROXML})

# Definition
#-DEASYCWMP_OM=1
add_definitions(-g3 -MD -Wall -DOS_LINUX=1 -pthread -lconfig -DPLAT_MODULE_DEVSM -DDEVEL=1 -DDEBUG=1 -DJSONC=1)


set(JT_SRAN_5G		jt_sran_5G)
set(JT_SRAN_CONF	AlarmTable.xml)
set(JT_SRAN_CONF_DIR	cfg_file)
set(JT_SRAN_CODE    clean.sh)

set(JT_SRAN_INSTALL_PREFIX ./)
set(CMAKE_INSTALL_PREFIX ${JT_SRAN_INSTALL_PREFIX})

# jt_sran
ADD_EXECUTABLE(${JT_SRAN_5G} ${DIR_SRCS})

# install 
# install(TARGETS ${JT_SRAN_5G}  DESTINATION ${CMAKE_INSTALL_PREFIX}/CUCP/)
# install(TARGETS ${JT_SRAN_5G}  DESTINATION ${CMAKE_INSTALL_PREFIX}/CUUP/)
# install(TARGETS ${JT_SRAN_5G}  DESTINATION ${CMAKE_INSTALL_PREFIX}/DU/)

install(FILES ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_5G} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUCP/app/ PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
install(FILES ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_5G} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUUP/app/  PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
install(FILES ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_5G} DESTINATION ${CMAKE_INSTALL_PREFIX}/DU/app/  PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)

install(FILES ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_CONF} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUCP/app/)
install(FILES ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_CONF} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUUP/app/)
install(FILES ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_CONF} DESTINATION ${CMAKE_INSTALL_PREFIX}/DU/app/)

install(PROGRAMS ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_CODE} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUCP/app/ PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
install(PROGRAMS ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_CODE} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUUP/app/ PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
install(PROGRAMS ${CMAKE_INSTALL_PREFIX}/debug/${JT_SRAN_CODE} DESTINATION ${CMAKE_INSTALL_PREFIX}/DU/app/ PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)

# install(DIRECTORY ${JT_SRAN_CONF_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUCP/)
# install(DIRECTORY ${JT_SRAN_CONF_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}/CUUP/)
# install(DIRECTORY ${JT_SRAN_CONF_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}/DU/)

