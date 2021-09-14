; 64位汇编

;声明函数原型
ExitProcess proto
.data
sum qword 0
arr qword 1,2,4,5,6
arrSize = ($ - arr)
arrLen = ($ - arr)/8
myStr byte "Hello World",0
; ch 个字节 12*1+1
strLen = ($ - myStr)
;代码段
.code
main proc
	mov	rax,0a5h			; 将a5h放入eax寄存器
	add	rax,6				; 将eax寄存器+6	
	mov sum,rax
	mov rax,arrLen
	mov rax,strLen

	mov rcx,0
	call ExitProcess
main endp
end