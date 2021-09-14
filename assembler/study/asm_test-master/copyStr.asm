; 计算数组中所有值的和
;1版
COMMENT	!
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
.data
	str1 byte "Hello World",0
	str2 byte sizeof str1 dup(0)
.code
main proc
	mov ecx,lengthof str1;存储源字符串长度
	mov eax,offset str1;存储源字符串地址
	mov ebx,offset str2;存储目标字符串地址
	mov dl,0;临时存储字符
L0:
	mov dl,[eax];将当前字符存储到临时寄存器
	mov [ebx],dl;将临时字符赋值到目标地址
	add eax,type byte;源字符串指针向后移动一个字节
	add ebx,type byte;目标字符串指针向后移动一个字节
	loop L0
invoke ExitProcess, 0
main endp
end main
!
;改进版
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
.data
	source byte "Hello World",0
	dest byte sizeof source dup(0)
.code
main proc
	mov esi,0;字符偏移
	mov ecx,lengthof source;存储源字符串长度
	mov al,0;临时存储字符
L0:
	mov dl,source[esi];将当前字符存储到临时寄存器
	mov dest[esi],dl;将临时字符赋值到目标地址
	inc esi
	loop L0
invoke ExitProcess, 0
main endp
end main