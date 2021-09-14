; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
section .data
text   db  "Hello World", 10 ; Output string and \n

section .text
global start
start:
  ; Every Unix system call will be (0×2000000 + unix syscall #) in MacOSX
  ; See also, http://thexploit.com/secdev/mac-os-x-64-bit-assembly-system-calls/
  mov rax, 0x2000004 ; write = 4
  mov rdi, 1
  mov rsi, text
  mov rdx, 13
  syscall

  mov rax, 0x2000001 ; exit = 1
  mov rdi, 0
  syscall
