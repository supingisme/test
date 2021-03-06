#!/bin/bash

# 显示 程序头信息
readelf -l a.out

# 
# Elf 文件类型为 EXEC (可执行文件)
# 入口点 0x400440
# 共有 9 个程序头，开始于偏移量64
# 
# 程序头：
#   Type           Offset             VirtAddr           PhysAddr
#                  FileSiz            MemSiz              Flags  Align
#   PHDR           0x0000000000000040 0x0000000000400040 0x0000000000400040
#                  0x00000000000001f8 0x00000000000001f8  R E    8
#   INTERP         0x0000000000000238 0x0000000000400238 0x0000000000400238
#                  0x000000000000001c 0x000000000000001c  R      1
#       [Requesting program interpreter: /lib64/ld-linux-x86-64.so.2]
#   LOAD           0x0000000000000000 0x0000000000400000 0x0000000000400000
#                  0x000000000000070c 0x000000000000070c  R E    200000
#   LOAD           0x0000000000000e10 0x0000000000600e10 0x0000000000600e10
#                  0x0000000000000224 0x0000000000000228  RW     200000
#   DYNAMIC        0x0000000000000e28 0x0000000000600e28 0x0000000000600e28
#                  0x00000000000001d0 0x00000000000001d0  RW     8
#   NOTE           0x0000000000000254 0x0000000000400254 0x0000000000400254
#                  0x0000000000000044 0x0000000000000044  R      4
#   GNU_EH_FRAME   0x00000000000005e0 0x00000000004005e0 0x00000000004005e0
#                  0x0000000000000034 0x0000000000000034  R      4
#   GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
#                  0x0000000000000000 0x0000000000000000  RW     10
#   GNU_RELRO      0x0000000000000e10 0x0000000000600e10 0x0000000000600e10
#                  0x00000000000001f0 0x00000000000001f0  R      1
# 
#  Section to Segment mapping:
#   段节...
#    00     
#    01     .interp 
#    02     .interp .note.ABI-tag .note.gnu.build-id .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn .rela.plt .init .plt .text .fini .rodata .eh_frame_hdr .eh_frame 
#    03     .init_array .fini_array .jcr .dynamic .got .got.plt .data .bss 
#    04     .dynamic 
#    05     .note.ABI-tag .note.gnu.build-id 
#    06     .eh_frame_hdr 
#    07     
#    08     .init_array .fini_array .jcr .dynamic .got 
