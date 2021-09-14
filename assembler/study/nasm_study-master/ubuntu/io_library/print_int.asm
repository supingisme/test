; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  minus db '-'

section .bss
  num resb 50

section .text
  global _start


_start:
  mov rdi, -79
  call print_int
  call exit

print_int:
  test rdi, 0x8000000000000000
  jne .unsigned
  ;print minus
  mov rbx, rdi ; tmp-copy
  mov rdi, minus
  call print_char
  neg rbx
  mov rdi, rbx
.unsigned:
  call print_uint
  ret

print_char:
  mov rax, 1
  mov rsi, rdi
  mov rdi, 1
  mov rdx, 1
  syscall
  ret


print_uint:
  mov r8, num ; store the str pointer
  mov rax, rdi
  mov rcx, 10
.loop:
  xor rdx, rdx ; we must initialize rdx. without this, segmentation fault occurs
  div rcx ;rax:rdx
  add rdx, 48
  mov [r8], dl
  inc r8 ; increment address
  cmp rax, 0
  jne .loop
.print:
  mov rax, 1
  mov rdx, 1 ;count
  mov rdi, 1
  mov rsi, r8
.print_loop:
  syscall
  cmp rsi, num
  je .end
  dec rsi ; decrement address
  jmp .print_loop
.end:
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
