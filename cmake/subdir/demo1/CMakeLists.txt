
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(CN)

aux_source_directory(./ DIR_SRCS)

add_subdirectory(log)
add_subdirectory(cn)
add_subdirectory(mme)
add_subdirectory(dim1/dim2)

include_directories(log mme cn)

# jt_sran
add_executable(main ${DIR_SRCS})

target_link_libraries(main log mme cn dim)
