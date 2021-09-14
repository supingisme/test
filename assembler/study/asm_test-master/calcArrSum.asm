;计算数组中所有值的和
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
 arr byte 123,234,123,12,5,23
.code
main proc
	mov eax,offset arr;将数组首地址赋值到eax寄存器种
	mov ecx,lengthof arr;将数组长度赋值到ecx循环寄存器中
	mov ebx,0;用ebx存和
	mov edx,0;byte无法直接赋值给ebx,先用dl存
L0:
	mov dl,byte ptr [eax]
	add ebx,edx
	add eax,type byte
	loop L0
	;结果等于208h
	invoke ExitProcess,0 
main endp
end main