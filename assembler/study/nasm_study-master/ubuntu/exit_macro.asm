; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  digit db 0, 10

section .text
  global _start

; define macro first
%macro exit 0
  mov rax, 60
  mov rdi, 0
  syscall
%endmacro

%macro printDigit 1
  mov rax, %1
  call _printRAXDigit
%endmacro

_start:
  printDigit 3
  printDigit 4
  exit

_printRAXDigit:
  add rax, 48
  mov [digit], al
  mov rax, 1
  mov rdi, 1
  mov rsi, digit
  mov rdx, 2
  syscall
  ret
