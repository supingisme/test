CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#project name
PROJECT(AutoDaemon)

aux_source_directory(. SRC_LIST)


include_directories( /usr/include/libxml2 )

find_library(LIB_MATH m /usr/lib64)
find_library(LIB_XML2 xml2 /usr/lib64) 
find_library(LIB_PTHREAD pthread /usr/lib64) 

link_libraries(${LIB_MATH} ${LIB_XML2} ${LIB_PTHREAD})

add_definitions( -MD -Wall )

ADD_EXECUTABLE(daemon ${SRC_LIST})

