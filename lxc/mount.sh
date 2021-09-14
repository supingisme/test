#!/bin/bash

# 在使用LXC 之前，必须启用cgroup 文件系统。使用下列命令挂载cgroup 文件系统。
mount -t cgroup cgroup /cgroup

# 向/etc/fstab 添加下列语句，就可以在系统启动时自动挂载cgroup 文件系统
echo "cgroup /cgroup cgroup defaults 0 0" >> /etc/fstab
