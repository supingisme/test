; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

;伪指令 表明这个是一个x86程序,能够访问32位寄存器和地址
.386
;声明内存模式 时flag,并确定了子程序的调用规范是stdcall
.model flat,stdcall
;申明运行时保存了4k的栈内存
.stack 4096
;声明函数原型
ExitProcess proto,dwExitCode: dword
;数据区,也就是段
.data
sum dword 0
;计算数组长度
arr dword 1,2,4,5,6
; 14h个字节 5*4
arrSize = ($ - arr)
arrLen = ($ - arr)/4
myStr byte "Hello World",0
; ch 个字节 12*1+1
strLen = ($ - myStr)


;代码段
.code
main proc
	mov	eax,0a5h			; 将a5h放入eax寄存器
	add	eax,6			; 将eax寄存器+6	
	mov sum,eax
	mov eax,arrLen
	mov eax,strLen
;+++++++++ 标志位测试 ++++++++++
;进位 CY
	;先初始化置0,这里不知道为什么ZR(零标志位没有为1)
	mov al,0
	;赋值0ffh 此时进位标志为0,因为0ffh没有溢出al寄存器
	mov al,0ffh
	; 此时al+1 就会进位
	add al,1
	;inc al 不会有效,因为inc 和dec 不影响进位标志符CY
;溢出 OV
	; 此时溢出为0
	mov al,+7fh;有符号必须要显式写出来
	; 溢出变为1,因为al最大为+7fh
	add al,1
;符号 PL
	mov al,0
	;这里先把PL置为0
	add al,1
	; 设置al为有符号整数0
	mov al,+0
	; al-2 等于负数,所以PL位为1
	sub al,2
;零 ZR
	mov al,0
	;这里al为1,ZR为0
	add al,1
	;al为0,ZR为1
	sub al,1
;奇偶 PE 是低8位中为1的位的个数,如果为偶数个则为1
	mov al,0 ;此时为偶数个
	add al,11001110b ;现在为奇数个
	add al,1 ;现在为偶数个
;辅助进位 AC,是b3是否有进位或错位(错误暂时不知道什么意思)
;0000 0(这个是位3,从0开始数,位3表示口语的第4位) 000
	mov al,1111b
	add al,1;此时al为00010000b,b4是由b3进位而来,所以AC 为 1
	invoke ExitProcess,0;退出程序
main endp
end main