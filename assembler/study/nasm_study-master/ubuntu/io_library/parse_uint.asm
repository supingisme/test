; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


section .data
  text db "1235", 0

section .text
  global _start

_start:
  mov rdi, text
  call parse_uint
  call exit

; rdi .. [input] number as null-terminated string
; rax .. [output] the parsed number
; rdx .. [output] counts
parse_uint:
  xor rcx, rcx ; increment count
  xor rax, rax
  mov rbx, 10
.loop:
  cmp byte[text+rcx], 0
  je .end
  mov sil, byte[text+rcx]
  mul rbx ; Be careful to modify rdx register!
  sub sil, 48
  add rax, rsi
  inc rcx
  jmp .loop
.end:
  mov rdx, rcx ; store count
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
