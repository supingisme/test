; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  newline db 10

section .bss
  wrd resb 100

section .text
  global _start

_start:
  mov rdi, wrd
  mov rsi, 10
  call read_word
  cmp rax, 0
  je exit
  mov rdi, rax
  call print_string
  call exit

; rdi .. address
; rsi .. count
read_word:
  mov rbx, rsi ; store count to compare later
  mov r8, rdi

  ; read
  mov rax, 0
  mov rdx, 100 ; count
  mov rsi, rdi
  mov rdi, 0 ; descripter
  syscall
  mov rdi, r8
  call strlen ; return in the rax registry
  cmp rax, rbx
  jle .end
  mov rax, 0 ; return 0 if word is too big for the buffer specified
  ret
.end:
  mov rax, r8 ;return rax as address
  ret

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
