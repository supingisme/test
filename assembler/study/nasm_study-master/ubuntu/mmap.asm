; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


; just like C language
%define O_RDONLY 0 
%define PROT_READ 0x1
%define MAP_PRIVATE 0x2

; data section
section .data
  fname: db 'test.txt', 0

; text section
section .text
  global _start

; this is the beginning of code
_start:
  mov rax, 2 ; open 
  mov rdi, fname
  mov rsi, O_RDONLY  ; define O_RDONLY 0
  mov rdx, 0 ; mode 
  syscall  ; open(test.txt, 0, 0)

  ; descripter -> processes address space
  mov r8, rax ; this is fd;;;;;;;;;;;
  mov rax, 9 ;sys_mmap ; mmap -> #define __NR_mmap 9
  mov rdi, 0 ; zero indicates that that the operating system is free to choose any start
  mov rsi, 4096 ;page size
  mov rdx, PROT_READ ;new memory region will be marked read only
  mov r10, MAP_PRIVATE ; pages will not be shared
  mov r9, 0
  syscall
  
; (gdb) x $rax
; 0x7ffff7ffc000: 0x61616161
; (gdb) x /s $rax
; 0x7ffff7ffc000: 'a' <repeats 12 times>, "\nbbb\nccccccccc\nddddddd\neee\n\nfff\n"
  mov rdi, rax ; rax holds a pointer to newly allocated pages
  call print_string
  call exit


exit:
  mov rax, 60
  xor rdi, rdi
  syscall
  ret

; accepts from rdi and return strlen with rax
strlen:
  xor rax, rax
.loop:
  cmp byte[rdi+rax], 0
  je .end
  inc rax
  jmp .loop
.end:
  ret

print_string:
  call strlen
  ; print
  mov rdx, rax
  mov rax, 1
  mov rsi, rdi
  mov rdi, 1
  syscall
  ret
