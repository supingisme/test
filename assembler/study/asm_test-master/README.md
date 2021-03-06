# asm 笔记

## 寄存器:

就是 cpu 中可以存储数据的器件,一个 cpu 中有多个器件

## 编译器

将汇编代码 编译为二进制机器码

汇编语言有 3 类指令

1. 汇编指令: 机器码的文字表示,有对应的机器码
2. 伪指令: 由编译器执行,计算器并不执行,没有对应的机器码
3. 其他符号: 如+-\*/ 由编译器识别,没有对应的机器码

cpu 要进行数据的读写 必须要与外部器件的芯片(我觉得就是内存的芯片)进行
3 种信息交互才能完成

1. 地址信息: 存储单元的地址信息(内存地址)
2. 控制信息: 器件的选择(选择了哪一个内存器件,一个主板上可以有多个内存条)
3. 数据信息: 读写的数据是什么

这 3 种信息通过总线传输
总线分为 3 类:

1. 地址总线
2. 控制总线
3. 数据总线

一条读内存的指令
`mov ax [3]` : 读取内存单元 3 的数据到寄存器 ax 中

### 地址总线

一个 cpu 有 32 根地址总线.每个线只能指示 0 或 1 的状态 那么 32 根一共有 2^32 种状态
即最多可以找到 0xffffffff 个地址,因为每个地址是一个字节 所以 32 位系统最大只能支持 4g 内存

### 数据总线

    数据总线的宽度决定了每次可以传输的数据大小,如8088cpu 数据总线有8根即宽度是8,那么
    每次只能传1个字节,8086cpu有16根数据总线,所有每次可以传输2个字节

### 控制总线

    cpu对外部器件的控制都是通过控制总线来进行的, 控制总线是一个总称,它是不同控制线的集合,
    有多少根控制线,就意味着cpu提供了对外部器件的多少种控制
    控制总线中 有一根叫 "读信号控制线" 当cpu向它输出低电平(我猜就是0)就表示将要接收数据;
    有一根线叫"写信号输出"的控制线负责传送写信号,这根控制线可以告诉外部器件 比如内存芯片,我要写东西

## 主板

    主板上有核心器件和一些主要器件,这些器件通过总线(3类)相连,这些器件有cpu,存储器,外围芯片组,
    扩展插槽等.扩展插槽上一般有RAM内存条和各类接口卡

## 接口卡

    计算机中所有可用程序控制其工作的设置都受到cpu的控制.cpu对外部的设备不能直接控制,如显示器,音箱等
    直接控制这些的是接口卡,而cpu 只要负责控制接口卡就行了

### 存储器芯片

    随机存储器(RAM): 可读可写,但必须带电运行,断电后存储内容丢失,就是内存条
    只读存储器(ROM): 只能读取,不能写入,关机后内容不消息 一般是系统的bios信息,或者一些只读光盘

# 寄存器

    一般cpu由 运算器,控制器,寄存器等器件组成,这些器件靠内部总线相连(不是前面的外部3种总线)
    * 在cpu种运算器进行信息处理
    * 寄存器进行信息存储
    * 控制器控制各种器件进行工作
    * 内部总线连接各种器件,在他们之间那些数据的传送

    8086 有14个寄存器,每个寄存器都是16位,可以存放2个字节
    AX,BX,CX,DX,SI,DI,SP,BP,IP,CS,SS,DS,ES,PSW, ## 通用寄存器
    AX,BX,CX,DX 通常存放一般性的数据
    8086 的上一代 cpu 寄存器是 8 位的,为了兼容它们,
    所有 AX,BX,CX,DX,也可以分为 AH,AL,BH,BL (H 表示 high,L 表示 low)

# 指令

`mov` 传送指令
`jmp` 转移指令 用来改变 CS,IP 的值
`jmp` 某一合法寄存器(如 ax) 将 `ax` 值转移到 `ip` 中,类似于 `mov ip,ax`

CS 寄存器:存放指令的段地  
Ip 寄存器:存放指令的偏移地址

# 以下部分来自<<汇编语言 基于 x86 架构>>

> 术语:

    LSB: 最低有效位

CPU 中有几个寄存器,一个高频时钟,一个控制单元(CU control unit)和一个算数逻辑(计算)单元(ALC arithmetic logic unit)

cpu 有四种总线

> 数据总线:传输 指令和数据
> io 总线: 在 cpu 和系统输入输出设备之间进行传输
> 控制总线: 用二进制信号对所有连接在系统总线上设备的行为进行同步
> 数据总线: 当前执行指令在 cpu 和内存之间进行传输数据时,数据总线用于保存指令和数据的地址

===单词:
`instruction` 指令

## 基本程序执行寄存器

    8个32位通用寄存器:
        EAX,EBX,ECX,EDX,EBP,ESP,ESI,EDI
    6个16位段寄存器:
        CS,SS,DS,ES,FS,GS
    一个处理器状态标志寄存器 EFLAGS(EFL)
    一个指令指针寄存器 EIP

### 通用寄存器

    > 主要用于算术运算和数据传输
    > EAX,EBX,ECX,EDX 存在重叠关系,可以用AX(后16位),AH(后16位前八位),AL(后16位的后八位)表示
    > 其他的寄存器只能用32位或16位来访问 如 ESI 用 SI 访问后16位

#### 寄存器的特殊用法

    乘除默认使用 EAX,通常称为扩展累加器寄存器
    ECX 是 cpu 默认的循环计数器
    ESP 用于寻址堆栈数据,通常称为扩展堆栈指针寄存器
    ESI,EDI 用于高速存储器传输指令,有时被称为扩展源变址寄存器和扩展目的变址寄存器
    EBP: 高级语言通过EBP来引用堆栈中的函数参数和局部变量,除了高级编程,它不用于一般
    算术运算和数据传输,通常称为扩展帧指针寄存器

### 段寄存器

    > 段: 就是预先分配的内存区域
    段寄存器表示的是`段`的基址
    保护模式中,段寄存器种存放的是段描述符表指针
    一些段中存放程序指令(代码),其他段存放变量(数据),还有一根堆栈段存放的是局部函数变量和
    函数参数

### 指令指针寄存器(EIP)

    > 存放了下一条将要执行指令的地址,某些机器指能控制EIP 使程序分支转向到一个新位置

### EFLAGS 寄存器

    > 包含了独立的二进制位,用于控制 cpu 的操作,或者反映一些cpu操作的结果,设置该标志位时,
    为1,清除或重置该标识位时,为0

### 控制标志位

    控制cpu 的操作,比如方向标志位,和中断标志位

### 状态标志位

    该标志位反映了cpu执行的算术和逻辑操作的结果.
    其中包括 溢出位,零标志位,辅助进位标志位,奇偶校验位和进位标志位.

#### CF 进位标志位

    与目标位置相比,无符号算术运算结果太大时,设置该标志位

#### OF 溢出标志位

    与目标位置相比,有符号算术运算结果太大或太小时,设置该标志位

#### SF 符号标志位

    算术或逻辑操作产生负结果时,设置该标志位

#### ZF 零标志位

    算术或逻辑操作产生的结果为零时,设置该标志位

#### AC 辅助进位标志位

    算术操作在8位操作数中产生了位3向位4的进位时,设置该标志位

#### PF 奇偶校验标志位

    结果的最低有效字节包含偶数个1时设置该标志位,否则清除该标志位,一般情况下,
    如果数据有可能被修改或损坏时,该标志位用于进行错误检测

### MMX 寄存器

    8个64位MMX寄存器是 单指令,多数据的特殊指令

### XMM 寄存器

    8个128位的XMM寄存器

### 浮点数据寄存器

    8个80位的浮点数据寄存器 分别为ST(0-7)

## 64 位 x86-64 处理器

    有几个基本特征:
    1. 向后兼容x86指令集
    2. 地址长度为64位 虚拟地址空间为2^64字节,但是当前芯片实现的情况只能使用低48位
    3. 允许使用64位通用寄存器,允许指令具有64位整数操作数
    4. 比x86 多了8个通用寄存器
    5. 物理地址位48位,支持最多256t的内存(ram)

编程须知:

> 对于十六进制数，书写时必须遵守下列规则：
> 以字母 A~F 开头的十六进制数，必须在前面多写一个 0。
> 否则，汇编程序会将字母开头的单词当成是变量名、语句标号之类的标识符，而不是数值。
> 必须在最后加上字母 H

### 伪指令

    .data 一个可以定义变量的段
    .code 包含可执行指令的段
    .stack 伪指令标志的程序区段定义了运行时堆栈,并设置了其大小 入 .stack 100h

### 指令

    > 一个指令有4个组成部分
    1. 标号(可选)
    2. 指令助记符(必须)
        比如: mov (传送|分配数值),mul 两数相乘,
        add 两数相加,jmp 跳转到一个新位置,
        sub 从一个数组减去另一个数值,call 调用一个子程序
    3. 操作数(通常是必须的)
        操作数个数范围是0-3个, 可以是寄存器,内存操作数,整数表达式和io端口
        stc 指令没有操作数 它表示进位标志位设为1
        inc 指令有一个操作数 用来+1
        imul有3个操作数
        imul eax,ebx,5 : 将ebx和5相乘,结果存放到eax寄存器中
    4. 注释
        单行注释 ;
        多行注释 COMMENT !
        !
        也可以用其他符号,但是中间不能出现 !
    [label:] mnemonic [operands] [;comment]

    代码区的标号必须用冒号结束 一般用于跳转和循环

#### 空操作指令

    > nop 在程序中占一个字节

    比如 mov ax,bx 会生成3个字节机器码 66 8b c3
    这时执行nop指令 就会凑满4个字节,cpu执行以下一个指令就会更快
    因为x86处理器被设计为从双字(就是双字不是双字节 双字时4个字节)础加载代码和数据

## 伪指令

    .model :告诉汇编器这个程序使用了哪一种存储模式
            32位程序总是使用平面(flat)存储模式
        `.model flag,stdcall`
    .stack :告诉汇编器位程序保留多少字节内存
        `.stack 4096`
    .code  :标记一个程序代码区的起点,通常下一行时程序的入口,按照惯例 是一个名为main的过程
        ```.code
            main proc
        ```
    endp   :标记一个过程的结束
        `main endp`
    end    :标记一个程序的结束 并要引用程序入口,end后面的代码都会被汇编器忽略
        `end main`
    invoke : 使编译器生成 push 和 call 语句,估计就是讲过程的内存地址存放到
    将要执行的cpu指令寄存器种,然后调用
    .data? 声明未初始化数据, .data中的数据时立即分配内存, .data?中的不会初始化,
    即不会分配内存

> 目标文件(.obj)就是对程序的机器语言翻译
> 链接器读取并检查目标文件,以便发现该程序是否包含了任何对链接库中过程的调用,

    并将它们与目标文件组合,以生成二进制可执行文件

### 内部数据类型

|  类型  | 用法                                                |
| :----: | :-------------------------------------------------- |
|  byte  | 8 位无符号整数                                      |
| sbyte  | 8 位有符号整数,s 表示 signed                        |
|  word  | 16 位无符号整数                                     |
| sword  | 16 位有符号整数                                     |
| dword  | 32 位无符号整数,d 表示 double                       |
| sdword | 32 位有符号整数                                     |
| fword  | 48 位整数,(保护模式中的远指针)                      |
| qword  | 64 位整数,q 代表 4(字,是字不是字节,一字等于 2 字节) |
| tbyte  | 80 位 (10 字节)整数,t 代表 10 字节                  |
| real4  | 32 位(4 字节) IEEE 短实数,有效数字 6                |
| real8  | 64 位(8 字节) IEEE 长实数,有效数字 15               |
| real10 | 80 位(10 字节) IEEE 扩展实数,有效数字 19            |

### 传统数据伪指令

| 伪指令 | 用法            |
| :----: | :-------------- |
|   db   | 8 位整数        |
|   dw   | 16 位整数       |
|   dd   | 32 位整数或实数 |
|   dq   | 64 位整数或实数 |
|   dt   | 定义 80 位整数  |

### dup 操作符

    使用一个整数表达式n作为计数器,为n个数据项分配存储空间
    比如 byte 20 dup(0) 就是生成20个值为0的byte
    byte 5 dup("Hello") 就是生成25字节的数据

### 当前地址计数器 \$

    最重要的符号之一
    计算数组,字符串长度经常会用到
    arr dword 1,2,4,5,6
    arrLen = (\$ - arr)

### 伪指令 equ

    跟 = 类似
    格式
        name equ 有效整数表达式
        name equ 标志(一个已经存在的符号名称,或已经用=或equ定义过了)
        name equ <文本或者数值>
    = 可以用来定义宏,可以多次重定义,但是equ不可以
    例如 timeLimit = 10
    之后可以重新设置为 timeLimit = 20

### 伪指令 textequ

    类似于equ,但是只创建文本宏
    格式:
        name textequ <文本>
        name textequ 文本宏
        name textequ %常量表达式
    rowSize = 5
    count textequ %(rowSize * 2)
    move  textequ <mov>
    setupAL  textequ <mov al,count>

    编译的时候 setupAL 会被汇编为 mov al,10

### 64 位和 32 位的区别

64 位开头
没有.386 伪指令
没有.model flat,stdcall
没有.stack 伪指令

使用 proto 关键字的语句不带参数

64 位 masm 不支持 invoke 伪指令
退出使用 mov ecx,0
call ExitProcess
并且 end 伪指令不需要指定程序入口点
64 位寄存器是 rax,rbx

> 列表文件: 包含了程序源代码的副本,再加上行号,偏移地址,翻译的机器代码和符号表

### C 语言 与 asm 的 对应类型

|     c     |  asm  |
| :-------: | :---: |
|   char    | byte  |
|   short   | word  |
|    int    | dword |
| long long | qword |
|   float   | real4 |
|  double   | real8 |

> x86 处理器使用小端序在内存中存取数据
> 0x12345678 在内存就是 78 56 34 12 ,低位在前面

# 第四章 数据传送,寻址,和算术运算

> movzx 全零扩展并传送

    就是最高位+0,只能用于无符号整数

> movsx 符号扩展并传送

    如果负数 前面全部补1,非负数则补0,只能用于有符号整数

> lahf 加载状态标志位到 ah

    将 EFLAGS 寄存器的低字节复制到AH寄存器,被复制的标志位包括: 符号标志位,零标志位,辅助进位标志位,
    奇偶标志位,和进位标志位.

> sahf 保存 ah 内存到状态标志位

    将ah寄存器的内容复制到 EFLAGS寄存器低字节 跟 lahf 反过来

> xchg 交换数据指令

    格式:
        xchg 寄存器,寄存器
        xchg 寄存器,内存
        xchg 内存,寄存器

### 地址偏移操作

    arr byte 10h,20h,30h
    mov al,arr ;al = 10h
    mov al,[arr+2] ;al = 30h

### 标志位符号

> | 标志名称 | 溢出 | 方向 | 中断 | 符号 | 零  | 辅助进位 | 奇偶 | 进位 |
> | :------: | :--: | :--: | :--: | :--: | :-: | :------: | :--: | :--: |
> |   符号   |  OV  |  UP  |  EI  |  PL  | ZR  |    AC    |  PE  |  CY  |

    1. 进位: 意味着无符号整数溢出,比如目的操作数是8位,但是指令产生的结果大于0ffh 那么溢出标志位为1
    2. 溢出: 意味着有符号整数溢出
    3. 零标志: 意味着结果为0
    4. 符号标志位: 操作结果为负数
    5. 奇偶: 目的操作数最低有效字节中1的个数是否为偶数,跟数值是否为奇偶不搭嘎
    6. 辅助进位: 意味着目的操作数最低有效字节中第三位(0位开始数)有进位,

> inc 加 1 指令 dec 减 1

    注意: inc 和 dec 不会影响进位标志位
    格式:
        inc reg/mem
        dec reg/mem

> add 加操作

    格式 add dest,source

> sub 减操作

    格式 sub dest,source

> neg 非 指令

    将操作数 转换为二进制补码,并将操作数的符号取反
    格式:
        neg reg
        neg mem

> 补码

    正数的补码就是原码
    负数的补码是 非符号位取反 再加1

## 与数据相关的运算符和伪指令

- offset 运算符 返回的是一个变量与其所在段起始地址之间的距离
- ptr 运算符可以重写操作数默认的大小类型
- type 运算符 返回的是一个操作数或数组中每个元素的大小(按字节计)
- lengthof 运算符返回的是数组中元素的个数
- sizeof 运算符返回的是数组初始化时使用的字节数
- label 伪指令 可以用不同的大小类型来重写定义同一个变量

> 代码段: 指的是长度为小于 64kb 的、地址连续、起始地址为 16（十进制）的倍数
> 的内存单元区域
> 数据段: 指的是长度小于 64kb 的、地址连续、起始地址为 16（十进制）的倍数的内存单元区域
> 因为偏移地址是 16 位,2^16 次方 b = 64kb,所以段的长度要小于 64kb
> 起始地址为 16 的倍数是因为起始地址 = 段地址 \* 16

> align 伪指令 对齐字节,只能设置一个变量

    默认对齐为 1
    就是定义变量的时候将这个变量对齐到某个值的倍数位置,
    比如 byte a 在0x01位置
    此时 byte b 就在0x02位置
    此时设置对齐为2
    那么 byte c 就是0x4位置
    那么 byte d 就是0x5位置

> ptr 运算符

    可以重写一个已经被声明过的操作数的大小类型,相当于c的类型转换

> type 运算符

    返回变量单个元素的大小

> lengthof 运算符

    返回数组中元素的个数

> sizeof 运算符

    返回 type * lengthof

> label 伪指令

    插入一个标号(c语言的变量),并定义它的大小属性,但是不为这个标号分配存储空间
    常见用法是,为数据段中定义的下一个变量提供不同的名称和大小属性.

### 直接寻址与间接寻址

    直接寻址就是 mov reg mem
    间接寻址操作符[]: 中括号中的内容(我测试只有寄存器有效)会被cpu当作地址对待,而不是值
    mov reg1,[reg2]: 取出reg2中的地址,再取值,然后赋值给reg1

### 变址操作数

    在寄存器的值上加一个常数产生一根有效地址,每个32位通用寄存器都可以用作变址寄存器
    格式:
        constant[reg]
        [constant + reg ]
        ```
            .data
            arr byte 10h,20h,30h
            .code
            mov esi,0
            mov al,arr[esi]; al此时是10h
            ;也可以
            mov esi,offset arr
            mov ax,[esi];ax = 10h
            mov ax,[esi+2];ax = 30h
        ```

### 指针

    如果一个变量包含另一个变量的地址,那么该变量为指针

```
    .data
    str0 byte "123123",0
    pStr0 dword offset str0
```

### typedef 运算符

    创建用户定义类型
    比如 创建一个指向byte的指针
        pbyte typedef ptr byte
    > ptr word 表示指向word类型的指针,word ptr mem 表示将 mem 中的值转为 word 使用
    > 书上没这么说,我猜的

### jmp 和 loop

    > 控制转移有2种基本类型
    1. 无条件转移: 无论什么情况都会转移到新地址,新地址加载到指令指针寄存器,使程序在新地址在进行执行,
        jmp 就是这种转移(跳转)
    2. 条件转移: 满足某种条件,则程序出现分支,各种条件转移指令还可以组合起来,形成条件逻辑结构,cpu 基于 ecx和标志寄存器的内容来解释真假条件

#### jpm 指令

    格式: jmp destination(用代码标号来标识这个标号会被汇编器转换为偏移量)

```buff:
        xxx
        jmp buff;就是跳转到buff标号那里
```

#### loop 指令: 按照 ECX 计数器循环,将程序块重复特定次数,ecx 的值是计数器,每循环一次,计数值-1

        执行的步骤:
            1. 将ecx减1
            2. 将ecx与0比较,如果不等于就跳转到标号
        > 如果ecx本来就等于0 那么减1等于0xffffffff也是会继续跳转的

### 64 位汇编的几点区别

    1. 如果将常数送入64位寄存器种,高位会被清0,
        比如 mov rax,0ffh;那么前面14位都会清0
    movsxd 指令: 符号扩展传送,带符号传送,
        如果mov rax,0ffh,那么前面14位会变f
    2. offset 运算符产生64位地址
    3. loop 使用rcx作为循环计数器

# 第五章 过程

    > 也称子程序或函数

### 堆栈的应用

1. 当寄存器用于多个目的时,堆栈可以作为寄存器的一个临时保存期
2. 执行 call 指令时,cpu 在堆栈中保存当前过程的返回地址
3. 调用过程时,输入数值也被称为参数,通过将其压入堆栈实现参数传递
4. 堆栈也为过程局部变量提供了临时存储区域,当寄存器被修改后,还可以恢复其初始值

## push 和 pop 指令

### push 指令

`push` 指令首先把 esp 执行的堆栈元素内容复制到一个 16 位或 32 位目的操作数中
再增加 esp 的值,如果操作数是 16,则 esp-2,操作数为 32 位则 esp-4
格式:
push reg/rem16
push reg/rem32
push imm32(估计是 32 位常数)

### pop 指令

`pop`指令首先把 esp 指向的堆栈元素内容复制到一个 16 或 32 位目的操作数中,再增加 esp 的值
如果操作数是 16 位,则 esp+2,若操作数为 32 位,则 esp+4

    格式:
        pop reg/mem16
        pop reg/mem32

### pushfd 和 popfd 指令

    pushfd 把32位 EFLAGS 寄存器内容压入堆栈,而 popfd 则把栈顶内容弹出刀片EFLAGS寄存器

    > 因为mov 指令不能把标识寄存器(EFLAGS)的内容赋值给一个变量,所以一般用pushfd保存标志位

### pushad, popad ,pusha , popa

    pushad 指令 按照 EAX,ECX,EDX,EBX,ESP(执行pushad命令之前的值),EBP,ESI,EDI的顺序,
    将所有的32位通用寄存器压入堆栈.popad 就会全部弹出到相应的寄存器

    pusha 就是按同样的顺序压入16位寄存器

## 定义过程(函数)

    格式:
        函数名 proc
            中间可以ret 强制返回此函数被调用的位置
        函数名 endp

一般返回值存在 eax 寄存器中
过程中的 jmp 可以跳过程中定义的标号,如果要定义全局标号 在名字后面加双冒号(::)

### call 和 ret 指令

`call` 指令调用一个过程,实际上就先把当前返回地址压入堆栈,再把被调用的过程的地址复制到
指令指针寄存器(EIP),当过程准备返回时,它的 ret 指令从堆栈把返回地址弹回到指令指针寄存器

### uses 伪指令

    跟在`proc`伪指令后面 ,声明这个函数要修改的所有寄存器名,这样汇编器就会自动生成 push 和 pop指令

## 链接库

    定义: 是一种文件,包含已经汇编为机器代码的过程(函数),链接库一开始是一个或多个源文件,
    这些文件再被汇编为目标文件,目标文件插入到一个特殊格式文件,该文件会被链接器识别,
    在主函数中,调用链接库的函数,链接器就会从链接库中取出对应的函数

# 第六章 条件处理

## and 指令

    按位与
    and dest,source
    格式:
        and reg,reg
        and reg,mem
        and reg,imm
        and mem,reg
        and mem,imm

> 标志位 :and 指令总是清除溢出和进位标志位,并根据目标操作数的值来修改符号标志位,零标志位,和奇偶标志位

## or 指令

    按位或
    or dest,source
    格式:
        or reg,reg
        or reg,mem
        or reg,imm
        or mem,reg
        or mem,imm

> 标志位 :or 指令总是清除进位和溢出标志位,并根据目标操作数的值来修改符号标志位,零标志位,和奇偶标志位

## not 指令

    反转操作数的所有位,其结果称为反码
    not 1001;0110
    格式:
    not reg
    not mem

> 标志位 :not 指令不影响操作位

## xor 指令

    按位异或

> 标志位 :xor 指令总是清除溢出和进位标志位,并根据目标操作数的值来修改符号标志位,
> 零标志位和奇偶标志位

## test 指令

    在两个操作数直接进行and操作,并根据运算结果设置符号标志位,零标志位和奇偶标志位,
    test 指令和 and 指令唯一不同的地方是,test 指令不修改目标操作数

> 标志位: test 指令总是清除溢出和进位标志位,其修改符号标志位,零标志位和奇偶标志位的方法和 and 指令相同

## cmp 指令

175 页 cmp 指令
