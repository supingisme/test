#!/bin/bash
# 荣涛 2021年7月28日

# 目的地址转换
# 从网络设备 ppp0 来的所有 TCP 目的端口为 81 的数据包，进行 DNAT，送往 192.168.0.2
iptables -t nat -A PREROUTING -i ppp0 -p tcp --dport 81 -j DNAT --to 192.168.0.2

# 源地址转换
# 源地址 192.168.0.0/24 网段 来的 IP 数据包，进行 SNAT 将其 源地址改为 本机 公网 IP
iptables -t nat -A POSTROUTING -s 192.168.0.0/24 -j SNAT --to 1.1.1.1

# 列出 NAT 表中规则
iptables -t nat -L -n

# 删除 snat 规则
iptables -t nat -D POSTROUTING -s 192.168.0.0/24 -j SNAT --to 1.1.1.1

# 动态 ip snat
iptables -t nat -A POSTROUTING -s 192.168.0.0/24 -j MASQUERADE


