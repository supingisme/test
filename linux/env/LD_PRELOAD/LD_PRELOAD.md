<center><font size='20'>LD_PRELOAD详解</font></center>
<br/>
<br/>
<center><font size='5'>RToax</font></center>
<center><font size='5'>2020年9月</font></center>

# 1. LD_PRELOAD的作用

系统在运行过程中，会首先加载该环境变量指定的函数库（在libc.so之前加载），如果函数库内包含了程序中执行的函数名，该可执行文件的函数将被重定向到LD_PRELOAD指向的函数中。

# 2. LD_PRELOAD的一个示例

## 2.1. 生成malloc动态库

### 2.1.1. mymalloc.h

```c
#ifndef _mymalloc_h
#define _mymalloc_h
#include <sys/types.h>

void *malloc(size_t size);
void free(void *ptr);

#endif
```

### 2.1.2. mymalloc.c

```c
#include <stdio.h>
#include "mymalloc.h"

void *malloc(size_t size)
{
	printf("call mymalloc.\n");
	return NULL;
}

void free(void *ptr)
{
	printf("call myfree.\n");
}
```

### 2.1.3. 编译动态库

```bash
gcc -fpic -shared mymalloc.c -o libmymalloc.so
```

## 2.2. 测试

### 2.2.1. 测试文件main.c

```c
#include "mymalloc.h"
#include <malloc.h>
#include <stdio.h>

int main()
{
	void *ptr = malloc(10);
	free(ptr);
}
```
### 2.2.2. 编译
```bash
gcc main.c
```
### 2.2.3. 直接运行
```
# ./a.out 
#
```
没有任何输出

### 2.2.4. 设定LD_PRELOAD环境变量

```bash
export LD_PRELOAD=$(pwd)/libmymalloc.so
```

### 2.2.5. 再次运行
```
# ./a.out 
call mymalloc.
call myfree.
# 
```
此时你会发现，在此bash（terminal）下执行系统指令，malloc也会被重定向到我们编写的动态库中。

```
# ls
call mymalloc.
call mymalloc.
call myfree.
call mymalloc.
call mymalloc.
call mymalloc.
call myfree.
call myfree.
call mymalloc.
call mymalloc.
call mymalloc.
call myfree.
call myfree.
ls: call myfree.
call myfree.
memory exhaustedcall myfree.
call myfree.
```
ls指令是执行失败的。

## 2.3. 完整的makefile

```makefile
all:
	@echo "make lib      :编译malloc动态库"
	@echo "make test     :编译示例程序"
	@echo "make ld       :设定LD_PRELOAD动态库"
	@echo "make reset    :取消使用LD_PRELAOD环境变量"
	@echo "               上面命令不起作用，请直接执行 # unset LD_PRELOAD"

lib:
	gcc -fpic -shared mymalloc.c -o libmymalloc.so 

test:
	gcc main.c

ld:
	@echo "请在终端输入：export LD_PRELOAD=$(PWD)/libmymalloc.so"

reset:
	unset LD_PRELOAD
```

# 3. 安全性问题

LD_PRELOAD重定向了posix API函数，或者说，不光是POSIX函数，试想一下，假如用这种方法替换鉴权类的接口会发生什么？

```c
bool auth_passwd(char *name, char *passwd);
```

这里我还没有时间调研，后面有时间再说。先在这里说一下。