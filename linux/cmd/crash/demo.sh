#!/bin/bash

# crash [vmcore] [vmlinux]

core_folder="127.0.0.1-2021-05-14-08\:57\:48"
kernel_vmlinux=`uname -r`
crash /var/crash/$core_folder/vmcore /usr/lib/debug/lib/modules/$kernel_vmlinux/vmlinux
