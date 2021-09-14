; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 
section .data
  hello_world db "Hello world!", 10
  ; See also https://www.tutorialspoint.com/assembly_programming/assembly_strings.htm
  hello_world_len equ $ - hello_world ; $(points to the byte after the last character of the string variable msg. ) - hello_world


global print_hello
global exit

print_hello:
  mov rax, 1
  mov rdi, 1
  mov rsi, hello_world
  mov rdx, hello_world_len
  syscall
  ret

exit:
  mov rax, 60
  mov rdi, 0
  syscall
  ret
