#!/bin/bash

# 创建 网桥
brctl addbr br0

# 配置 网桥 IP 地址
ip address add 192.168.0.1/24 dev br0

# 启动 网桥
ip link set dev br0 up

# 查看网桥的IP 地址
ip address show br0

# 添加 veth 设备 veth1 到 br0 中
brctl addif br0 veht0

# 显示信息
brctl show

# 从 veht0 设备发送数据
ping -I veht0 192.168.0.1

# 在新的命令行中 真挺 br0 中的数据，可以看到从 veht0 设备的 MAC 地址 发送来的数据包
tcpdump -i br0 -elnv
