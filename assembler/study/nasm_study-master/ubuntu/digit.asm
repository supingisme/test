; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 


section .data
  digit db 0, 10 ; little endian
				; db: define byte 

section .text
  global _start

_start:
  call printREXDigit
  call exit

printREXDigit:
  mov rax, 1  ; digit 1
  add rax, 48 ; char '1'
  mov [digit], al
  mov rax, 1 ;write
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
