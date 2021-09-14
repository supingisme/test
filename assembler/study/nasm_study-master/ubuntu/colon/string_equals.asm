; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 
section .text
global string_equals

; accepts two pointers to strings and compares them. Returns 1 if they are equal otherwise 0
;rdi .. The pointer to the first string
;rsi .. The pointer to the second string
;rax .. 1(True) or False(0)
string_equals:
  mov dl, byte[rsi]
  ; cmp byte[rdi], [sil] ; NOT Indirect Memory Addressing because sil is a pointer
  cmp byte[rdi], dl
  jne .false
  cmp byte[rdi], 0
  je .true
  inc rdi
  inc rsi
  jmp string_equals
.false:
  mov rax, 0
  ret
.true:
  mov rax, 1
  ret
