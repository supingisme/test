	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"Hello World."
	.text
	.globl	helloworld
	.type	helloworld, @function
helloworld:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	helloworld, .-helloworld
	.globl	T1
	.data
	.align 16
	.type	T1, @object
	.size	T1, 16
T1:
	.long	1
	.zero	4
	.quad	helloworld
	.globl	T2
	.align 16
	.type	T2, @object
	.size	T2, 16
T2:
	.long	2
	.zero	4
	.quad	helloworld
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	T1+8(%rip), %rdx
	movl	$0, %eax
	call	*%rdx
	movq	T2+8(%rip), %rdx
	movl	$0, %eax
	call	*%rdx
	movl	$3, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
