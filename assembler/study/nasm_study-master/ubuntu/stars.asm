; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  msg: db 'Displaying 9 stars\\n', 10
  len: equ $ - msg
  s2 times 9 db '*'

section .text
  global _start

_start:
  mov rax, 1   ; 
  mov rdi, 1
  mov rsi, msg
  mov rdx, len
  syscall

  mov rax, 1  ; write
  mov rdi, 1  ; write(fd=1)
  mov rsi, s2 ; string
  mov rdx, 9  ; len = 9
  syscall
  call exit

	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 10
	syscall


exit:
  mov rax, 60 ; exit
  mov rdi, 0  ; exit(0)
  syscall
  ret
