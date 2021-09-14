; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  text db 'abcdefghijk', 0
  newline db 10

section .text
  global _start


_start:
  mov rdi, text ; Be careful that rdi is the pointer to the head of the text
  call print_string
  ;call print_newline
  call exit

; accepts from rdi and return strlen with rax
strlen:
  xor rax, rax
.loop:
  cmp byte[rdi+rax], 0
  je .end
  inc rax
  jmp .loop
.end:
  ret

print_string:
  call strlen
  ; print
  mov rdx, rax
  mov rax, 1
  mov rsi, rdi
  mov rdi, 1
  syscall
  call print_newline
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
