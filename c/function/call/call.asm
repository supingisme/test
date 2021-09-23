func1:
	pushq	%rbp
	movq	%rsp, %rbp
	nop
	popq	%rbp
	ret
func2:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	func1
	nop
	popq	%rbp
	ret
func3:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	func2
	nop
	popq	%rbp
	ret
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	func3
	movl	$0, %eax
	popq	%rbp
	ret
