; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  text db "hello world", 10

section .text
  global _start
_start:
  mov rax, 1
  mov rdi, 1
  mov rsi, text
  mov rdx, 13
  syscall

  mov rax, 60
  mov rdi, 0
  syscall
