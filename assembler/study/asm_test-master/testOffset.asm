;测试 offset和align
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	arr word 1,2,3,4,5
	pArr dword 0
	tempV byte 0;用来弄乱对齐用的
	aVal byte 1;0040400f
	bVal byte 2;00404010
	align 2
	cVal byte 3;本来应该是00404011,但是这个地址不是2的倍数,所以cVal的内存地址是00404012
	dVal byte 4;此时又恢复了1个字节对齐,地址为00404013
.code
main proc
	;假设此时arr 的偏移地址为00404000h
	; offset arr + 4 就是 00404004h,也就是数值3的地址
	; + 4 就是加4个字节,一个word是2个字节,所以esi存了数值3的地址
	mov esi,offset arr + 4
	mov pArr,offset arr;此时pArr保存了arr的地址,就是00404000h
	mov pArr,offset aVal
	;创建指针
	invoke ExitProcess,0 
main endp
end main