;翻转字符串
;使用堆栈
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
.data
  arrList dword 10h,20h,30h,40h,50h
  arrLen dword lengthof arrList
  sum dword 0
.code
main proc
	mov esi,offset arrList
	mov ecx,arrLen
	call arraySum
	mov sum,eax
	invoke ExitProcess, 0
main endp

;计算数组中所有32位数字的和
arraySum proc ;在这里用uses ecx esi 也可以
	push ecx;防止影响外部函数的循环次数,先压入栈
	push esi;防止影响外部函数的 esi
	mov eax,0;先把和置空
L0:	
	;从数组的第一个值开始加,加到最后一个
	add eax,[esi]
	add esi,type dword
	loop L0
	;恢复外部函数的esi和ecx
	pop esi
	pop ecx
	ret
arraySum endp

end main


