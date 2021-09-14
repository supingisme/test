; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  msg: db "Allocated 16 kb of memory!", 10
  len: equ $ - msg

section .text
  global _start

_start:
  mov rax, 12 ; sysblk
  xor rdi, rdi
  syscall ; return `0x601000`; the current setting of the program stack

  add rax, 16384 ; 16K-byte reserved
  mov rdi, rax
  mov rax, 12 ; sysblk
  syscall ; return `0x605000`.

  ; check errno
  cmp rax, 0
  jl exit

  call exit

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
