# 指定cmake最小版本
cmake_minimum_required(VERSION 2.6) 

project(add)

message("Project Name: " ${PROJECT_NAME})

#设置编译参数
set(CMAKE_C_FLAGS "-g -Wall")

#设置库文件文件输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


#递归获取目录下所有的C文件
file(GLOB_RECURSE c_files ${PROJECT_SOURCE_DIR}/src/*.c)

#生成动态库和静态库
add_library(add_lib_shared  SHARED ${c_files})
add_library(add_lib_static 	STATIC ${c_files})

#将动态库和静态库的名字设置为 add
set_target_properties(add_lib_shared PROPERTIES OUTPUT_NAME "add")
set_target_properties(add_lib_static PROPERTIES OUTPUT_NAME "add")

#设置动态库版本
set_target_properties(add_lib_shared PROPERTIES VERSION 1.0 SOVERSION 1)
