; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 
[BITS 16]
; master boot record (MBR) is loaded at 0x7c00
; For more information, see https://www.glamenv-septzen.net/view/614
boot:
  mov al, '!' ; AL = code of character to display
  mov ah, 0x0e ; function number; Write Character in TTY Mode
  ; for more information, see https://en.wikipedia.org/wiki/INT_10H#List_of_supported_functions
  mov bh, 0x00 ; Set background/border color
  mov bl, 0x07 ; BL = Background/Border color (border only in text modes)
  int 0x10 ;call Interrupt ;BIOS video service
  ; an infinite loop
  jmp $

; check `objdump -D -b binary -mi386 -Maddr16,data16,intel reset`:
; 1fc:	00 00                	add    BYTE PTR [bx+si],al
; 1fe:	55                   	push   bp
; 1ff:	aa                   	stos   BYTE PTR es:[di],al
;; $ evaluates to the assembly position at the beginning of the line containing the expression
;; $$ evaluates to the beginning of the current section
times 510-($-$$) db 0 ; filled with 0
; Boot signature. See also https://en.wikipedia.org/wiki/Master_boot_record#structure_of_a_modern_standard_mbr 
db 0x55
db 0xaa
