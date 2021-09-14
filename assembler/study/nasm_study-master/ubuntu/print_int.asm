; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


section .bss
  digitSpace resb 100 ; resb is the byte unit size
  digitSpacePos resb 8 ; stores address

section .text
  global _start

_start:
  mov rax, 123
  call _printRAX

  ;exit
  mov rax, 60
  mov rdi, 0
  syscall

_printRAX:
  mov rcx, digitSpace ; peek the address of digitSpace.
  mov rbx, 10 ; new line
  mov [rcx], rbx
  inc rcx
  mov [digitSpacePos], rcx ; peek the address of digitSpace+1
_printRAXLoop:
  mov rdx, 0
  mov rbx, 10
  div rbx
  push rax ;12, 1, 0
  add rdx, 48 ;remainder 3, 2, 1

  mov rcx, [digitSpacePos] ;peek digit position 
  mov [rcx], dl ;dl is lower-8bits of rdx
  inc rcx
  mov [digitSpacePos], rcx ; save the rcx, which value is pointer

  pop rax ; 12, 1, 0
  cmp rax, 0
  jne _printRAXLoop ; if not equal, then jump

; Now rcx is in order of '\n', '3', '2', '1'.
; let's print with sys_write until '\0' comes
_printRAXLoop2:
  mov rcx, [digitSpacePos]
  mov rax, 1
  mov rdi, 1
  mov rsi, rcx
  mov rdx, 1
  syscall

  mov rcx, [digitSpacePos]
  dec rcx
  mov [digitSpacePos], rcx

  cmp rcx, digitSpace ; if je, stop.
  jge _printRAXLoop2

  ret ; don't forget that expression. Without it, it occurs `Segmentation fault (core dumped)`
  
