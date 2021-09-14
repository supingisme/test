;测试 testPtr
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	aVal dword 12345678h
	wordList word 5678h,1234h
	val1 byte 0
	val2 word 0
	val3 dword 0
	val4 qword 0
	arr1 word 1,2,3,4,5
	     word 6,7,8,9,10
	str1 byte "Hello World",0
	val5 label word;与val6共用同一个内存空间
	val6 dword 12345678h
	val7 dword 0
.code
main proc
	;下面这行会报错,因为bVal是4个字节的dword类型,不能赋值给16位的ax寄存器
	;mov ax,aVal
	mov ax,word ptr aVal;这行语句可以,因为word ptr 可以将aVal强转为word类型(16位)
	;此时ax为5678,因为aVal在内存中是 78 56 34 12,转换为word后 就为 78 56, 所以ax 的值为5678
	;也可以将小类型转为大类型, 这里转换之后只是改变了取字节的个数
	mov eax,0
	mov eax,dword ptr wordList;这里eax就会变成12345678h,原来wordList是16位,只会取出5678,
	;但是转成32位就会取出12345678
	;获取变量的类型字节大小
	mov al,type val1;1
	mov al,type val2;2
	mov al,type val3;4
	mov al,type val4;8
	mov al,lengthof arr1;5,不是10,因为换行的不算
	mov al,lengthof str1;12
	mov al,sizeof arr1;5*2
	mov ax,0
	mov ax,val5;val5等于val6的前16位就是5678h

	mov eax,offset val6;取val6的地址赋值给ax
	mov val7,eax
	mov ebx,val7;此时ebx 等于val6的地址
	mov ebx,[eax];此时ebx 等于val6的值 12345678h
	invoke ExitProcess,0 
main endp
end main