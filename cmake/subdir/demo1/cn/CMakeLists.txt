aux_source_directory(. DIR_CN_SRCS)

add_subdirectory(amf)

add_library(cn  ${DIR_CN_SRCS})

target_link_libraries(cn amf)
