;typedef
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
pword typedef ptr word;//定义一个指向word类型的指针 pword
.data
 wordList word 10h,20h,30h,40h;定义一个word数组
;这里wordList是word;类型的数组,这里赋值给dword 的 pWordList
;就是将内存地址赋值给pWordList 
 pWordList dword wordList
 word1 word 10h;定义一个word类型 word1
 pWord1 dword word1;pWord1 为地址
 pWord2 pword word1;pWrod2 也是指针
.code
main proc
	mov eax,0
	mov ax,wordList;10h
	mov eax,0
	mov eax,dword ptr wordList;00100020h
	mov eax,0
	mov eax,pWordList;mem
	mov eax,0
	mov ax,word1;10h
	mov eax,0
	mov eax,pWord1;mem
	mov eax,0
	mov eax,pWord2;mem
	mov eax,0
	mov ebx,pWord1;mem
	mov ax,[ebx];10h
	mov ax,0
	mov ebx,pWord2;mem
	mov ax,[ebx];10h
	invoke ExitProcess,0 
main endp
end main