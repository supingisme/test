         ;代码清单6-1
         ;文件名：c06_mbr.asm
         ;文件说明：硬盘主引导扇区代码
         ; 
      
         jmp near start
         
  mytext db 'L',0x07,'a',0x07,'b',0x07,'e',0x07,'l',0x07,' ',0x07,'o',0x07,\
            'f',0x07,'f',0x07,'s',0x07,'e',0x07,'t',0x07,':',0x07
  number db 0,0,0,0,0
  
  start:
         mov ax,0x07c0                  ;设置数据段基地址 
         mov ds,ax
         
         mov ax,0xb800                 ;设置附加段基地址，也就是将ES寄存器指向显存的起始地址 
         mov es,ax
         
         cld													 ;方向清零标志，将DF标志位清零，代表传送是正向的
         mov si,mytext  						   ;SI与DS组成数据段的地址 DS:SI 代表数据的真实物理地址                
         mov di,0    									 ;DI与ES组成显存的物理地址 ES:DI 代表显存的真实物理地址
         mov cx,(number-mytext)/2      ;实际上等于 13
         rep movsw 										 ;循环movsw，直到cx寄存器内容为0（rep指令代表反复传送）
     
         ;得到标号所代表的偏移地址
         mov ax,number
         
         ;计算各个数位
         mov bx,ax
         mov cx,5                      ;循环次数 
         mov si,10                     ;除数 
  digit: 
         xor dx,dx
         div si
         mov [bx],dl                   ;保存数位
         inc bx 											 ;使bx寄存器里的值加1
         loop digit
         
         ;显示各个数位
         mov bx,number 								 ;将number的汇编地址传送给BX寄存器
         mov si,4                      ;bx+si 得到字符串的每一个字符，SI从4递减到0，这是由于要先显示万位上的数字
   show:
         mov al,[bx+si]
         add al,0x30									 ;得到它对应的ASCII码
         mov ah,0x04									 ;对应的颜色属性
         mov [es:di],ax								 ;AX中是一个完整的字，前8位是显示属性值，后8位是字符的ASCII码
         add di,2		 			     ;DI寄存器在之前用过，现在在“Label offset:” 字符串后面，刚好我们想让number的汇编地址在这里显示
         dec si						     ;SI-1,从number代表的汇编地址的万位到个位，dec指令会影响SF标志位，当SI寄存器的值为0的时候，SF的标志位置1
         jns show							 ;判断SF标志位是否为0，当SF标志位不为0，继续执行show处的代码。当SF标志位为0，则跳过这条指令执行下一条指令。
         
         mov word [es:di],0x0744		;高字节0x07是黑底白字的属性，低字节0x44是字符‘D’的ASCII码

         jmp near $   							;相当于 infi: jmp near infi

  times 510-($-$$) db 0             ; 计算512字节中，需要填满的字节有哪些。
                   db 0x55,0xaa     ;一个有效的主引导扇区，最后两字节必须是0x55 0xaa