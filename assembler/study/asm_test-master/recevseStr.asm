;翻转字符串
;使用堆栈
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
.data
	source byte "Hello World",0
	dest byte sizeof source dup(0)
.code
main proc
	mov esi,0;存偏移
	mov ecx,lengthof source;存储源字符串长度
L0:
	movzx eax,source[esi];复制一个字符
	push eax;压入堆栈
	inc esi;增加偏移
	loop L0;将所有的字符压入栈
	;重置偏移
	mov esi,0
	mov ecx,lengthof source;
L1:
	pop eax
	mov dest[esi],al
	inc esi
	loop L1
invoke ExitProcess, 0
main endp
end main