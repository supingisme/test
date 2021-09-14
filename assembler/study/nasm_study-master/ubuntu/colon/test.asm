; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 
; nasm -f elf64 lib.asm
; nasm -f elf64 test.asm
; ld -o res test.o lib.o
; ./res
extern string_equals

section .bss
  ans: resb 1 ; reserve a byte.(NOT db(define byte))

section .rodata
  str1: db 'abcd', 0
  str2: db 'abcd', 0

section .text
  global _start

_start:
  mov rdi, str1
  mov rsi, str2
  call string_equals
  ; print result
  add al, 48 ; stringify
  mov [ans], al
  mov rax, 1
  mov rdi, 1
  mov rdx, 1
  ; Be careful not to be `mov rsi, [ans]`, because the ans is address itself.
  mov rsi, ans ; you can't replace ans with other registers.
  syscall
  call exit

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
