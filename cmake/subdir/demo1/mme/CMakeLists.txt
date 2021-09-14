aux_source_directory(. DIR_MME_SRCS)

add_library(mme ${DIR_MME_SRCS})


include_directories(../log)