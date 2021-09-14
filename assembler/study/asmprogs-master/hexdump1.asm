; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
;Description: Simple program that converts binary values into hexadecimal strings.
;run this way: hexdump1 < (input file)
;build this way: nasm -f elf -g -F stabs hexdump1.asm

SECTION .bss					; containing uninitialized data
BUFFLEN equ 16					; setting size of the buffer
Buff resb BUFFLEN				; text buffer itself

SECTION .data					; containing initialized data
HexStr db " 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ", 10
HexLen equ $-HexStr

Digits db "123456789ABCDEF"

SECTION .text					; containing code

global _start:					; entry point

_start:

nop

; Read a buffer full of text from StdIn

Read:
mov eax, 3					; specify sys_read call
mov ebx, 0					; specify StdIn
mov ecx, Buff					; set the offset of the buffer to ecx
mov edx, BUFFLEN				; set the amount of bytes to be read in edx
int 80h						; call sys_read
mov ebp, eax					; save # of bytes read in ebp for later usage
cmp eax, 0					; check if the EOF is reached
je Done;					if EOF --> jump to Done

; Preparing registers for the operating with data read into the buffer
mov esi, Buff 					; place the adress of the buffer into esi
mov edi, HexStr					; place the adress of the line into edi
xor ecx, ecx					; clear line string pointer to 0

; Go through the buffer and convert binary values to hexodecimal digits
Scan:
xor eax, eax					; clear the eax register

; Calculating the offset into HexStr, which is the value in ecx * 3
mov edx, ecx					; Copy the character counter into edx
shl edx, 1					; multipllying the value in edx by 2 due to shifting left on 1 position
add edx, ecx					; complete the multiplication X 3

; Get a character from the buffer and put it both in eax and ebx
mov al, byte [esi+ecx]				; put the byte from input buffer in al
mov ebx, eax					; duplicate the byte in bl for second nybble

; Look up low nybble character and insert it into the string
and al, 0Fh					; mask out all but the low nybble
mov al, byte [Digits+eax]			; look up the char equivalent to nybble
mov byte [HexStr+edx+1], bl			; write MSB char digit to line string

; Look p the high nybble character and insert it into the string
shr bl, 4					; shift high four bits in bl to the right to get the high nybble in four low bits
mov bl, byte [Digits + ebx]			; look up char equivalent to nybble
mov byte [HexStr + edx +1], bl			; write MSB char digits to line string

; Bump the bufer pointer to the next character and see if we are done
inc ecx						; increment value of the ecx (line string pointer)
cmp ecx, ebp					; compare to the length of buffer (to the number of chars)
jna Scan					; loop back if ecx <= the lenght of the buffer

; Write the line of hexadecimals from the buffer to StdOut
Write:
mov eax, 4					; specify sys_write call
mov ebx, 1					; specify output Descriptor to StdOut
mov ecx, HexStr					; pass the pointer of HexStr
mov edx, HexLen					; pass the length of HexLen
int 80h						; call sys_write
jmp Read					; go back to read some more chars into the buffer

Done:
mov eax, 1					; specify sys_exit call
mov ebx, 0					; set ebx value to 0
int 80h						; call sys_exit
