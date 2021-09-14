; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 


section .data
  correct: dq -1

section .text
  global _start

_start:
  mov rax, [0x400000-1]; this is a bad memory address: segment fault
				; [0x400000] is ok!!!!!!!!!
  mov rax, 60
  xor rdi, rdi
  syscall
