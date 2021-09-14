; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .bss
  input resb 1

section .data
  global _start

_start:
  call read_char
  mov rdi, rax
  call print_char
  call exit

read_char:
  mov rax, 0
  mov rdi, 0
  mov rsi, input
  mov rdx, 1
  syscall
  mov rax, input
  ret

print_char:
  mov rax, 1
  mov rsi, rdi
  mov rdi, 1
  mov rdx, 1
  syscall
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
