; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 

; equ -> like '=' in ansi-c

STDIN equ 0 ; stdinno
STDOUT equ 1 ; stdoutno
STDERR equ 2 ; stderrno

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

section .data
  text db "Hello, world!", 10

section .text
  global _start


_start:
  mov rax, SYS_WRITE
  mov rdi, STDOUT
  mov rsi, text
  mov rdx, 14
  syscall

  mov rax, SYS_EXIT
  mov rdi, 0
  syscall
