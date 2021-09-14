; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 



section .data
	num1: equ 100 ; is just num1 = 100;
	num2: equ 50
	msg: db "Sub is correct", 10


section .text
  global _start

_start:
  mov rax, num1
  mov rbx, num2
  add rax, rbx  ; this is just for add algorithm
  cmp rax, 150
  jne .exit
  jmp .rightSum

.rightSum:
  mov rax, 1
  mov rdi, 1
  mov rsi, msg
  mov rdx, 15 ; count
  syscall
  jmp .exit

.exit:
  mov rax, 60
  mov rdi, 0
  syscall
