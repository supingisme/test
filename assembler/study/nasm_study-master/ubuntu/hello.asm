; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 17:18:41 CST. 
; global, section, db are directives which control the translation process.
section .data ; hold global variables
  text db "hello world", 10 ; db: create byte data
  ex2 times 5 db 49 ; store "11111" string

section .text ; hold instructions
  global _start
; labels: just readable names and addresses
_start: ; entry point
  mov rax, 1 ;write
  mov rdi, 1 ;stdout
  mov rsi, text
  mov rdx, 13
  syscall
  mov rax, 1 ; write
  mov rdi, 1 ; stdout
  mov rsi, ex2 
  mov rdx, 7
  syscall

  ; Without the syscall, interrupt with 6 will occur, 
  ;		in turn `Segmentation fault` message on the terminal
  mov rax, 60 ; exit
  mov rdi, 0
  syscall
