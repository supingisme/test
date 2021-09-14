#!/bin/bash

sudo awk -F\' '$1=="menuentry " {print i++ " : " $2}' /etc/grub2.cfg

#Linux 3.10.0-957.12.2.el7.x86_64 x86_64
#	3 - 内核版本.
#	10 - 主修订版本.
#	0-957 - 次要修订版本.
#	12 - 补丁版本.
