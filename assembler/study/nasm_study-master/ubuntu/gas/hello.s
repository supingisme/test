.section .text
  .globl _start

_start:
  movq $1, %rax
  movq $2, %rdi
  movq $message, %rsi
  movq $14, %rdx
  syscall

  movq $60, %rax
  xor %rdi, %rdi
  syscall

message:
  .ascii "Hello, world!\n"
