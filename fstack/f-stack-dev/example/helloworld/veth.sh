#!/bin/bash
# <rongtao@sylincom.com>

ifconfig veth0 10.170.7.169 netmask 255.255.255.0
ifconfig veth1 10.170.7.170 netmask 255.255.255.0

ifconfig veth0
ifconfig veth1
