; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
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

; obviouse there is argument, and it's two arguments, usage: %1 %2
%macro printDigitSum 2
  mov rax, %1
  add rax, %2
  call _printRAXDigit
%endmacro

_start:
  printDigitSum 3, 4
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
