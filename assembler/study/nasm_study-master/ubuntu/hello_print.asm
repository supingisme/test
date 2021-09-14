; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


section .data
  text db "hello world", 10, 0
  text2 db "World?", 10, 0

section .text
  global _start
_start:
  mov rax, text
  call _print

  mov rax, text2
  call _print

  mov rax, 60 ; exit
  mov rdi, 0
  syscall

; 一个一个的出栈; push rax; 
_print:
  push rax ; push text data
  mov rbx, 0
_printLoop:
  inc rax ; increment pointer to rax
  inc rbx ; increment 0
  mov cl, [rax]
  cmp cl, 0
  jne _printLoop

  mov rax, 1 ; write
  mov rdi, 1 ; stdout
  pop rsi ; retrieve text data
  mov rdx, rbx ;count
  syscall
  ret
