; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 

; include -> like "#include" in C

%include "linux64.inc"

section .data
  text db "Hello, world!", 10, 0

section .text
  global _start

_start:
  print text
  exit
