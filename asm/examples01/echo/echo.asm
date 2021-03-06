; ----------------------------------------------------------------------------
; echo.asm
;
; NASM implementation of a program that displays its commandline arguments,
; one per line.
; ----------------------------------------------------------------------------

	global	_main
	extern	_printf

	section .text
_main:
	mov	ecx, [esp+4]	        ; argc
	mov	edx, [esp+8]		; argv
top:
	push	ecx			; save registers that printf wastes
	push	edx

	push	dword [edx]		; the argument string to display
	push	format			; the format string
	call	_printf
	add	esp, 8			; remove the two parameters

	pop	edx			; restore registers printf used
	pop	ecx

	add	edx, 4			; point to next argument
	dec	ecx			; count down
	jnz	top			; if not done counting keep going

	ret
format:
	db	'%s', 10, 0