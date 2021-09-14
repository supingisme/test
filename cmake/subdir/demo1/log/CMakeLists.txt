aux_source_directory(. DIR_LOG_SRCS)

add_subdirectory(assert)


add_library(log ${DIR_LOG_SRCS})

target_link_libraries(log assert)
