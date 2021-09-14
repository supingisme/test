; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  chr db 56
  newline db 10

section .text
  global _start

_start:
  mov rdi, chr
  call print_char
  call print_newline
  call exit

print_char:
  mov rax, 1
  mov rsi, rdi
  mov rdi, 1
  mov rdx, 1
  syscall
  ret

print_newline:
  mov rax, 1
  mov rdi, 1
  mov rdx, 1
  mov rsi, newline
  syscall
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
