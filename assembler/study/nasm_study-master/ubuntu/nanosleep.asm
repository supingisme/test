; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


section .data
  delay dq 5, 500000000 ; 5.5seconds ; dq..quaduple word

section .text
  global _start

_start:
  mov rax, 35 ;#define __NR_nanosleep 35 -> 
				;int nanosleep(const struct timespec *req, struct timespec *rem);
  mov rdi, delay
  mov rsi, 0
  syscall

  mov rax, 60 ; exit
  mov rdi, 0
  syscall
