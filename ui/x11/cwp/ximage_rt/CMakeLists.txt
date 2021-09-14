CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(ximage)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

aux_source_directory(./src DIR_SRCS)

include_directories(./include)

find_library(CONFIG config /usr/lib64)
find_library(UI_X11 X11 /usr/lib64)
find_library(PTHREAD pthread /usr/lib64)
find_library(RT rt /usr/lib64)
find_library(MATH m /usr/lib64)

link_libraries(${CONFIG} ${UI_X11} ${PTHREAD} ${RT} ${MATH})

add_definitions(-MD -Wall -pthread)

ADD_EXECUTABLE(ximage ${SRC_LIST} ${DIR_SRCS})


