CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(hello)

AUX_SOURCE_DIRECTORY(src COMMON_SRCS )
AUX_SOURCE_DIRECTORY(vos COMMON_SRCS )

include_directories(src)
include_directories(vos)

add_definitions( -MD -Wall -DOS_LINUX)

ADD_EXECUTABLE(hello1 ./hello1.c ${COMMON_SRCS}) 
ADD_EXECUTABLE(hello2 ./hello2.c ${COMMON_SRCS})
