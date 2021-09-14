#EasyCWMP代码迁移编译CMakeLists.txt文件
#	2020.03.30	<rongtao@sylincom.com>

CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 
PROJECT(test_cwmp)

#添加源文件 
aux_source_directory( ./om_rpc   DIR_SRCS) 
aux_source_directory( ./simu_om   DIR_SRCS) 
aux_source_directory( ./src  DIR_SRCS) 
aux_source_directory( ../../../../../jt_sran5G/jtsran5G/om_tools/src DIR_SRCS)

#设置编译参数 
set(CMAKE_C_FLAGS "-g -Wall")

#添加头文件路径 
include_directories(
	/usr/include 
	/usr/include/curl 
	/usr/local/include 
    ../../../../../jt_sran5G/platform/include/
	../../../../../jt_sran5G/jtsran5G/om_tools/include/
    /usr/include/libxml2
	./src 
	./ 
	./simu_om )

#添加库 
find_library(RT rt /usr/lib64) 
find_library(DL dl /usr/lib64) 
find_library(MATH m /usr/lib64) 
find_library(CRYPT crypt /usr/lib64) 
find_library(PTHREAD pthread /usr/lib64)
find_library(JSONC json-c /usr/lib64)
find_library(UCI uci /usr/local/lib/)
find_library(UBOX ubox /usr/local/lib/)
find_library(UBUS ubus /usr/local/lib/)
find_library(CURL curl /usr/lib64)
find_library(XML2 xml2 /usr/lib64)
find_library(MICROXML microxml /usr/lib64)
find_library(GROS gros ../../../../../jt_sran5G/platform/target_libs/)
find_library(CONFIG config /usr/lib64)

#link库
link_libraries(${DL} ${RT} ${MATH} ${CRYPT} ${PTHREAD}  ${JSONC} ${UCI} ${UBOX} ${UBUS} ${CURL} ${MICROXML} ${GROS} 
${CONFIG} ${XML2})

#定义 
add_definitions(-g3 -MD -Wall -w -DDEVEL=1 -DDEBUG=1 -DJSONC=1 -DEASYCWMP_OM -DOS_LINUX=1)

# easycwmpd 
ADD_EXECUTABLE(main ${DIR_SRCS})

#生成动态库和静态库 
#add_library(acc_lib_shared  SHARED ${DIR_SRCS}) 
#add_library(acc_lib_static 	STATIC ${DIR_SRCS})

#将动态库和静态库的名字设置 
#set_target_properties(acc_lib_shared PROPERTIES OUTPUT_NAME "crtl") 
#set_target_properties(acc_lib_static PROPERTIES OUTPUT_NAME "crtl")

#set(LIBRARY_OUTPUT_PATH ../lib) 

#设置动态库版本 
#set_target_properties(acc_lib_shared PROPERTIES VERSION 1.0 SOVERSION 1) 

#安装库文件 
#install(TARGETS acc_lib_shared DESTINATION /usr/lib64 PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)

#安装头文件 
#file(GLOB crtl_hdrs ./crtl/*.h) 
#file(GLOB crtl_hdrs_easy ./crtl/easy/*.h) file(GLOB crtl_hdrs_bits ./crtl/bits/*.h) file(GLOB crtl_hdrs_network ./crtl/network/*.h)

#install(FILES ${crtl_hdrs} DESTINATION /usr/local/include/crtl/) 
#install(FILES ${crtl_hdrs_easy} DESTINATION /usr/local/include/crtl/easy) 
#install(FILES ${crtl_hdrs_bits} DESTINATION /usr/local/include/crtl/bits) 
#install(FILES ${crtl_hdrs_network} DESTINATION /usr/local/include/crtl/network)




