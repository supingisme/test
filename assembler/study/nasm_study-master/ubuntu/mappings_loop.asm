; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


section .data
  correct: dq -1
  
section .text
  global _start

; jump to _start , it's a loop code
_start:
  jmp _start
