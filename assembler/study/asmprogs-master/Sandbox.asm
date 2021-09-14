; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
section .bss
  Bufflen equ 1024			; Length of the buffer
  Buff: resb Bufflen			; Text-buffer itself
section .data
  ErrMsg: db "Input file is empty!",10 
  ErrLen: equ $-ErrMsg 

section .text

global _start

_start:

nop

Read: mov eax, 3			; specify sys_read call
      mov ebx, 0			; specify File Descriptor 0: Standard Input
      mov ecx, Buff			; Pass adress of the buffer to read to
      mov edx, Bufflen			; tell sys_read to read one character from StdIn
      int 80h				; call sys_read
      mov esi, eax			; copy sys_read return in esi for safekeeping
      cmp eax, 0			; look if eax < 0, if eax=0 --> error
      je Err
      cmp eax, 0			; look at sys_read return value in eax
      je Done				; jump to Done if eax=0 (that means that EOF character was read)
; set up the registers for the process buffer step
      mov ecx, esi			; put the number of bytes read into the ecx
      mov ebp, Buff			; put the adress of buffer into ebp
      dec ebp				; decrement ebp to adjust count to offset (to avoid 'out of one' eror)
; go through the buffer and convert lowercase to uppercase characters:

Scan: cmp byte [ebp+ecx], 61h		; test current char in the buffer against 'a'
      jb Next				; if below 'a' in ASCII chart, then not lowercase
      cmp byte [ebp+ecx], 7Ah		; test input char against 'z'
      ja Next				; if above 'z', then not lowercase     
      sub byte [ebp+ecx], 20h		; substract 20h from lowercase to get appercase character
      
Next: dec ecx				; decrement counter
      jnz Scan				; if no 0 (if characters remain in the buffer), jump to Scan
      
; Write the full buffer to the StdOut

Write:	mov eax, 4			; specify sys_write call
	mov ebx, 1			; specify File Desctriptor 1: Standard Output
	mov ecx, Buff			; pass adress of the character to write
	mov edx, esi			; pass the # of bytes of data in the buffer
	int 80h				; call sys_write ...
	jmp Read			; ... then go to beginning to get another chatacter

Err:	mov eax, 4			; specify sys_write call
	mov ebx, 2			; specify sys_write File Descriptor 2: Standard Error
	mov ecx, ErrMsg			; specify an error mesage for Standard Error
	mov edx, ErrLen			; specify length of the error message
	int 80H 			; call sys_write
	mov eax,1 			; specify sys_exit call
	mov ebx,0 			; set ebx to 0
	int 80H 			; call sys_exit

Done:	mov eax, 1			; code for exit sys_call
	mov ebx, 0			; return a code of zero to Linux
	int 80h				; call exit sys_call
	
nop
