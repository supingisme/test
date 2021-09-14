; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 



section .data
  name: db 'Zara ali', 10
  name_len: equ $-name

section .text
  global _start

_start:
  mov rax, 1
  mov rsi, name
  mov rdx, name_len
  syscall

  mov [name], dword 'Nura'

  mov rax, 1
  mov rsi, name
  mov rdx, name_len
  syscall
  call exit

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
