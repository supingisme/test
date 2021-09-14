; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
	
section .data
	msg db "hello world"

section .text
	global _start 

_start:
	;; write syscall
	mov rax, 1
	;; file descriptor, standard output
	mov rdi, 1
	;; message address
	mov rsi, msg
	;; length of message
	mov rdx, 14
	;; call write syscall
	syscall

	;; exit
	mov rax, 60
	mov rdi, 0

	syscall
