#!/bin/bash
# 荣涛 热补丁
# 2021年9月27日

function press_any_key()
{
	echo -e "\033[1;31m>>>> $1 <<<<\033[m"
	read -r -p "Press any key to continue..." __input
}

press_any_key "Generate patch file..."
diff -up qemu-img.c patches/qemu-img.c > qemu-img.patch
diff -up softmmu/qdev-monitor.c patches/qdev-monitor.c > qdev-monitor.patch 

press_any_key "compile"
/home/rongtao/libcareplus/src/libcare-patch-make --clean *.patch

