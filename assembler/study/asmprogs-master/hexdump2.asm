; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:03 CST. 
;Executable name: 	hexdump2
;Version:		1.0
;Created Date:		14.01.15
;Last update:		14.01.15
;Author:			Jeff Duntemann
;Description:		A simple hex dump utility demonstrating the use of assembly language procedure

;Build using these commands:
; nasm -f elf -g -F stabs hexdump2.asm
; ld -o hexdump2 hexdump2.o


SECTION .bss		; section containing uninitialize data
BUFFLEN EQU 10		; setting size of the buffer
Buff resb BUFFLEN	; buffer itself

SECTION .data		; section containing initialize data

; Here we have two parts of the single useful data sructure, implementing
; the text line of hex dump utility. The first part displays 16 bytes in hex,
; separated by spaces. Immediately following is a 16-character line,
; delimited by vertical bar characters. Because they are adjacent, the two parts
; can be referenced separately or as a single contiguous unit.
; Remember that if DumpLin is to be used separately, you must append EOL 
; before sending it to the Linux console.

DumpLin db " 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 "
DUMPLEN EQU $-DumpLin
ASCLin db " |................| ", 10
ASCLEN EQU $-AscLin
FULLEN EQU $-DumpLin

; The HexDigits table is used to convert numeric values to their hex 
; equivalents. Index by nybble without a scale: [HexDigits+eax]

HexDigits: db "0123456789ABCDEF"

; This table is used for ASCII character translation, into the ASCII portion
; of hex dump line, via XLAT or ordinary memory lookup.
; All printable characters "play through" as themselves. The high 128 characters are
; translated to ASCII period (2Eh). The non-printable characters int he low 128 
; are also translated to ASCII period, as is char 127.

DotXlat:
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh
db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh
db 40h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,5Bh,5Ch,5Dh,5Eh,5Fh
db 60h,61h,62h,63h,64h,65h,66h,67h,68h,69h,6Ah,6Bh,6Ch,6Dh,6Eh,6Fh
db 70h,71h,72h,73h,74h,75h,76h,77h,78h,79h,7Ah,7Bh,7Ch,7Dh,7Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh

SECTION .text			; section, containing code

; ClearLine: 	Clear a hex dump line string to sixteen 0 values
; Updated:	14.01.15
; IN:		Nothing
; RETURNS:	Nothing
; MODIFIES:	Nothing
; CALLS:	DumpChar
; DESCRIPTION:	The hex dump line string is clearedto binary 0 by calling DumpChar 16 times
; 		passing it 0 each time.

ClearLine:
pushad		; save all caller's GP registers 
mov edx, 15	; we're going to go 16 pokes, counting from 0
.poke:
mov eax, 0	; Tell DumpChar to poke a 0
call DumpChar	; calling DumpChar procedure, inserting 0 into the hex dump string
sub edx, 1	; DEC doesn't affect CF!
jae .poke	; jump back if edx>=0
popad		; restore all caller's GP registers
ret		; go home

; DumpChar:	"Poke" a value into the hex dump line string.
; Updated:	14.01.15
; IN:		Pass the 8-bit value to be poked in eax
;		Pass the value position in theline (0-15) in edx
; RETURNS:	Nothing
; MODIFIES:	eax, ASCLin, DumpLin
; CALLS:	Nothing
; DESCRIPTION:	The value passed in eax will be put both in the hex dump portion
;		and the ASCII portion of the line, at the position passed in edx,
;		represented by a space where it's not a printable character.

DumpChar:
push ebx	; save caller's ebx register
push edi	; save caller's edi register
; Firstwe insert the input char into the ASCII portion of the dump line

mov bl, byte[DotXlat+eax]	; translate non-printables to '.'
mov byte[ASCLin+edx+1], bl	; Write to ASCII portion
; Next we insert the hex equivalent of the input char into the hex portion
; of the hex dump line
mov ebx, eax			; save a second copy of the input char
lea edi, [edx*2 + edx]		; Calc offset into line string (edx*3)

; look up low nybble character and insert it to into the line string
and eax, 0000000Fh		; Mask out all bat the low nybble
mov al, byte[HexDigits+eax]	; Look up the char equiv. of nybble
mov byte[DumpLin+edx+2], al	; Write the cahr equiv. to line string

; look up low nybble character and insert it to into the line string
and ebx, 000000F0h		; Mask put all but the second-lowest nybble
shr ebx, 4			; Shift high 4 bits of byte into low 4 bits
mov bl, byte[HexDigits+ebx]	; look up char equiv. of nybble
mov byte[DumpLin+edi+1], bl	; Write the char equiv. to line string

; Done! Let's go home!
pop edi				; restore caller's edi
pop ebx				; restore caller's ebx
ret				; return to caller

; PrintLine:	Display DumpLin to StdOut
; Updated:	14.01.15
; IN:		Nothing
; RETURNS:	Nothing
; MODIFIES:	Nothing
; CALLS:	Kernel sys_write
; DESCRIPTION:	The hex dump line string DumpLin is displayed to stdOut using int 80h sys_write.
;		All GP registers are preserved.

PrintLine:
pushad		; save all caller's GP registers on the stack
mov eax, 4	; specify sys_write call
mov ebx, 1	; specify stdOut file descriptor
mov ecx, DumpLin	; pass the line string into to display it
mov edx, DUMPLEN	; pass the length of the string to display
int 80h			; call kernel sys_write
popad 			; restore all caller's GP registers
ret 			; return to caller

; LoadBuff:	Fills the buffer with data from StdIn via int 80h sys_read
; Updated:	14.01.15
; IN:		Nothing
; RETURNS:	# of bytes read in ebp
; MODIFIES:	ecx, ebp, Buff
; CALLS:	kernel sys_write
; DESCRIPTION:	Loads a buffer full of data (BuffLen bytes) from stdIn using int 80h sys_read and places it in Buff.
;		Buffer offsetcounter ecx is zeroed, because we are starting in on a new buffer full of data.
;		Caller must test value in ebp: If ebp contains zero on return, we hit EOF on stdIn.
;		Less than 0 on return in ebp indicates some kind of error.

LoadBuff:
push eax		; save caller's eax
push ebx		; save caller's ebx
push edx		; save caller's edx
mov eax, 3		; specify sys_read call
mov ebx, 0		; specify StdIn file descriptor
mov ecx, Buff		; pass the offset of the buffer to ecx
mov edx, BUFFLEN	; pass number of bytes to read at one pass
int 80h			; call sys_read
mov ebp, eax		; saves # of bytes read from file for later
xor ecx, ecx		; clear buffer pointer ecx to 0
pop edx			; restore caller's edx
pop ebx			; restore caller's edi
pop eax			; restore caller's eax
ret 			; return to caller

global _start:					; entry point

_start:

nop
nop
; Whatever initialization needs doing before the loop scan starts is here:
xor esi, esi		; clear total byte counter to 0
call LoadBuff		; Read first buffer of data from stdIn
cmp ebp, 0		; check if EOf is reached
jbe Exit		; jump to Exit if epb<=0

; Go through the buffer and convert binary bytes values to hex digits:
Scan:
xor eax, eax		; clear eax to 0
mov al, byte [Buff+ecx]	;Get a byte from the buffer into al
mov edx, esi		; copy total counter into edx
and edx, 0000000Fh	; Mask put lower 4 bits of total counter
call DumpChar		; call the char poke procedure

; Bump the buffer point to the next character and see if buffer's done
inc esi			; Incremet total chars process counter
inc ecx			; Increment buffer pointer
cmp ecx, ebp		; Compare with # chars in the buffer
jb .modTest		; if we've processed all chars in the buffer...
call LoadBuff		; go fill buffer again
cmp ebp, 0		; If ebp=0, sys_read reached EOF on stdIn
jbe Done		; If we've got EOF we're done!

; See, if we are at the end of a block of 16 and need to display a line:
.modTest:
test esi, 0000000Fh	; Test 4 lowest bits in counter for 0
jnz Scan		; If counter is not modulo 16, loop back
call PrintLine		; ...otherwise print the line
call ClearLine		; clear hex dump line to 0's
jmp Scan		; continue scanning the buffer

; All done!

call PrintLine		; printing the "leftovers" line
mov eax, 1		; code for exit sys_call
mov ebx, 0		; return a code of 0
int 80h			; make an exit kernel call
