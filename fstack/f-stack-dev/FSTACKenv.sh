#!/bin/bash
# <*! 添加 FStack + DPDK 环境变量> rongtao@sylincom.com

export RTE_SDK=/opt/fstack/f-stack-dev/dpdk
export RTE_TARGET=x86_64-native-linuxapp-gcc

export FF_PATH=/opt/fstack/f-stack-dev
export FF_DPDK=$RTE_SDK/$RTE_TARGET

