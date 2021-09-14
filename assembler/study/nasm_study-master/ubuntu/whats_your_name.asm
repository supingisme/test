; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


; 存放程序中已经被初始化的全局变量 -> 静态内存分配
section .data
  question db "What is your name? "
  answer db "Hello, "

;bss segment：用来存放程序中未初始化的全局变量的一块内存
; bss -> blockstarted by symbol -> 静态内存分配
section .bss
  name resb 16

;存放代码的内存
section .text
  global _start
_start:
  call _printText1
  call _getName
  call _printText2
  call _printName

  mov rax, 60 ; exit
  mov rdi, 0
  syscall

_getName:
  mov rax, 0 ; read
  mov rdi, 0
  mov rsi, name
  mov rdx, 16
  syscall
  ret

_printText1:
  mov rax, 1 ; write
  mov rdi, 1
  mov rsi, question
  mov rdx, 19
  syscall
  ret

_printText2:
  mov rax, 1 ; write
  mov rdi, 1
  mov rsi, answer
  mov rdx, 7
  syscall
  ret

_printName:
  mov rax, 1 write
  mov rdi, 1
  mov rsi, name
  mov rdx, 16
  syscall
  ret
