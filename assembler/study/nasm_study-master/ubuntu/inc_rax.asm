; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


section .text
  global _start

_start:
  mov rax, 1
  call incRax
  cmp rax, 2 ; if is not equal, segment fault !!!!!!!!!!!!! attention please
  je exit ; if equal -> jump
	; the cmp and je maybe must use together, otherwise, segment fault happend

incRax:
  inc rax ; ++ -> add 1 == add rax, 1
  ;add rax, 1 ; same as "inc rax"
	      ; -- -> minus 1 => dec
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
