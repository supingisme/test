; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
;Description: Simple program that that demonstrates the XLAT instraction in action.
;run this way: xlatl < (input file)
;build this way: nasm -f elf -g -F stabs xlat1.asm
;link this way: ld -o xlat1 xlat1.o

SECTION .data					; containing initialized data
StatMsg db "Processing...", 10
StatLen equ $-StatMsg
DoneMsg db "... done1", 10
DoneLen equ $-DoneMsg
; The following translation table translates all lowercase charecters to uppercase characters.
; It also translates all unprintable characters to spaces, except of LF and HT.
UpCase:
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,09h,0Ah,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh
db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh
db 40h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,5Bh,5Ch,5Dh,5Eh,5Fh
db 60h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,7Bh,7Ch,7Dh,7Eh,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h

; The following translation table is "stock" in that it translates all printable characters
; as themselves, and converts all non printable characters to spaces, except of LF and HT. 
; You can modify it to translate anything you want to any character you want.

Custom:

db 20h,20h,20h,20h,20h,20h,20h,20h,20h,09h,0Ah,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh
db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh		
db 40h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,5Bh,5Ch,5Dh,5Eh,5Fh
db 60h,61h,62h,63h,64h,65h,66h,67h,68h,69h,6Ah,6Bh,6Ch,6Dh,6Eh,6Fh
db 70h,71h,72h,73h,74h,75h,76h,77h,78h,79h,7Ah,7Bh,7Ch,7Dh,7Eh,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h
db 20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h,20h

SECTION .bss					; containing uninitialized data
READLEN equ 1024					; setting size of the buffer
ReadBuffer: resb READLEN				; text buffer itself

SECTION .text					; containing code

global _start:					; entry point

_start:

nop

; Display "I'm working..." mesage via standard err

mov eax, 4					; specify sys_write call
mov ebx, 2					; specify output Descriptor to StdOut
mov ecx, StatMsg				; pass the pointer of HexStr
mov edx, StatLen				; pass the length of HexLen
int 80h						; call sys_write	

; Read a buffer full of text from StdIn

Read:
mov eax, 3					; specify sys_read call
mov ebx, 0					; specify StdIn
mov ecx, ReadBuffer				; set the offset of the buffer to ecx
mov edx, READLEN				; set the amount of bytes to be read in edx
int 80h						; call sys_read
mov ebp, eax					; save # of bytes read in ebp for later usage
cmp eax, 0					; check if the EOF is reached
je Done;					if EOF --> jump to Done

; Preparing registers for the operating with data read into the buffer
mov ebx, UpCase 				; place the offset of the table into ebx
mov edx, ReadBuffer				; place the offset of the Buffer into edx
mov ecx, ebp					; place the number of bytes in the buffer into ecx

; Use the xlat instruction to translate the data in the buffer
; (the commented out instructions do the same thing that xlat does) 
Translate:
;	xor eax, eax				; clear high 24 bits of eax
mov al, byte [edx+ecx]				; load character into al for translation
; 	mov al, byte [UpCase+eax]		; translate character in Al via table
xlat						; translate character in Al via table
mov byte [edx+ecx], al				; put the translated char back into the buffer
dec ecx						; decrement character count
jnz Translate					; if there are more chars in the buffer - repeat

; Write the buffer full of translated text to stdOut
Write:
mov eax, 4					; specify sys_write call
mov ebx, 1					; specify file Descriptor: StdOut
mov ecx, ReadBuffer				; pass the offset of the buffer
mov edx, ebp					; pass the # bytes of data to the buffer
int 80h						; make sys_write kernel call
jmp Read					; loop back and load another buffer full

; Display the "I'm done ..." message via stdErr
mov eax, 4					; specify sys_write call
mov ebx, 2					; specify file Descriptor: StdErr
mov ecx, DoneMsg				; pass the offset of the message
mov edx, DoneLen				; pass the length of the message
int 80h						; make sys_write kernel call


Done:
mov eax, 1					; specify sys_exit call
mov ebx, 0					; set ebx value to 0
int 80h						; call sys_exit
