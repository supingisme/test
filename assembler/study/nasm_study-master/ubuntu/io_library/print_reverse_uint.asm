; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .bss
  str: resb 100

section .text
  global _start

_start:
  mov rdi, 356
  call print_reverse_uint
  call exit

print_reverse_uint:
  mov rsi, rsi ; increment count
  mov rax, rdi
  mov rcx, 10
.loop:
  div rcx ;rax:rdx
  add rdx, 48
  mov [str+rsi], dl
  inc rsi
  cmp rax, 0
  je .print
  ; without this instruction, Floating point exception (core dumped)
  mov rdx, 0
  jmp .loop
.print:
  ; print_char
  mov rax, 1
  mov rdi, 1
  mov rdx, rsi
  mov rsi, str ; 0x33, 0x35, 0x36. Note that little endian: multibyte numbers are stored in memory starting with the least significant bytes. The advantage of little endian is that we can discard the most significant bytes effectively converting the number from a wider format to a narrower one.
  syscall
  ret
  


exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
