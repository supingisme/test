#!/bin/bash 

# 查找 rpm 包
rpm -qa | grep bpftrace

# 卸载 rpm 包
rpm -e bpftrace
