
; make it equal
STDIN equ 0
STDOUT equ 1
STDERR equ 2

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

; there still have macro in assembly?? i wondering
%macro exit 0
  mov rax, SYS_EXIT
  mov rdi, 0
  syscall
%endmacro


%macro print 1
  mov rax, %1
  mov rbx, 0
%%printLoop:
  mov cl, [rax]
  cmp cl, 0
  je %%endPrintLoop
  inc rax
  inc rbx
  jmp %%printLoop
%%endPrintLoop:
  mov rax, SYS_WRITE
  mov rdi, STDOUT
  mov rsi, %1
  mov rdx, rbx
  syscall
%endmacro
