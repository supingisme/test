.section .data

  var1:
    .int 40
  var2:
    .int 20
  var3:
    .int 30

.section .text
  .globl _start

_start:
  movl (var1), %ecx
  cmpl (var2), %ecx
  jg check_third_var
check_third_var:
  cmpl (var3), %ecx
  jg _exit
  movl (var3), %ecx

_exit:
  movl $1, %eax
  movl %ecx, %ebx
  int $0x80
