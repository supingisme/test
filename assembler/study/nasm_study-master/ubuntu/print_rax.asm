; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  codes: db '0123456789ABCDEF'
  cr: db 10

section .text
  global _start

; don't assume that the registers are filled with zero.
_start:
  mov rax, 0x1122334455667788 ; Note that most significant bit(MSB) is 0

  mov rdi, 1
  mov rdx, 1
  mov rcx, 64

.loop:
  push rax
  sub rcx, 4
  sar rax, cl ; sar: Shift arithmetic right. Most-significant bit (MSB) is shifted back

  ; rax = 0x00 00 00 00 00 00 00 01
  ; mask  0x00 00 00 00 00 00 00 0f
  ; fetch most least bit (MLB)
  and rax, 0xf

  lea rsi, [codes + rax] ; Computes the effective address itself of the second operand (the source operand) and stores it in the first operand

  ;set for syscall
  mov rax, 1
  ; stores rcx value, because syscall leaves rcx and r11
  push rcx
  syscall
  pop rcx

  pop rax
  test rcx, rcx ; test can be used for the fastest zero check command
  jnz .loop ; if, non zero jump loop; exactly same as jne
  mov rax, 1
  mov rdi, 1 ; file descripter
  mov rsi, cr ; output \n
  mov rdx, 1 ; count
  syscall

  ; call exit system call
  mov rax, 60
  xor rdi, rdi
  syscall
