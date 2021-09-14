; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
%macro pushr 1
%ifidn %1, rflags
pushf
%else
push %1
%endif
%endmacro

pushr rax
pushr rflags

%macro print 1
  %ifid %1
  %else
    %ifnum %1
      mov rdi, %1
    %else
      ; %fatal would stop assembling completely
      %error "String literals are not supported yet"
    %endif
  %endif
%endmacro

section .data
  myhello: db 'hello', 10, 0

section .text
  global _start

_start:
  print myhello
  print 42

  mov rax, 60
  syscall

