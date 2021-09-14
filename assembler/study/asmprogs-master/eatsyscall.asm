; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
section .data ; Section containing initialized data 
EatMsg: db "Eat at Joe,s!",10 
EatLen: equ $-EatMsg 
section .text ;Section containing code 
global _start ; Linker needs this to find the entry point! 
_start: 
nop 
mov eax,4 
mov ebx,1 
mov ecx,EatMsg 
mov edx,EatLen 
int 80H 
mov eax,1 
mov ebx,0 
int 80H ;Specify Exit syscall Return a code of zero Make syscall to terminate the program
