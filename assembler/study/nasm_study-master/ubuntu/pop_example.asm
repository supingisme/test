; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 



section .data
  digit db 0, 10 ; little endian

section .text
  global _start

  ;	|   |      | 8 |
  ;	| 4 |  ->  | 4 | ->
  ; +---+      +---+
  ; first in, after out, 
_start:
  push 4				
  push 8
  push 3
  pop rax
  call _printREXDigit
  pop rax
  call _printREXDigit
  pop rax
  call _printREXDigit
  call exit

_printREXDigit:
  add rax, 48 ;#define __NR_shutdown 48
				; of course is not 48, is a + 48 = 'a'
  mov [digit], al ; al is 8-bit register, is AX's low 8-bits 
				;[] is 间接地取操作数方式
				;这句话是将al放到digit指向的内存中
  mov rax, 1 
  mov rdi, 1
  mov rsi, digit 
  mov rdx, 2
  syscall
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
