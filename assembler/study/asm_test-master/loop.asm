;typedef
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
 
.code
main proc
	mov ax,0
	mov ecx,0
begin:
	inc ax
	loop begin
	invoke ExitProcess,0 
main endp
end main