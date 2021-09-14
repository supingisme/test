#include <sys/types.h>

//modify_ldt()  reads  or  writes the local descriptor table (ldt) for a process.  The ldt is a per-process
//memory management table used by the i386 processor.  For more information on this table, see an Intel 386
//processor handbook.

/*
大多数用户态程序不使用局部描述符表，这样内核就定义了一个缺省的LDT，供大多数进程共享
缺省的LDT存放在default_ldt中

如果在某些情况下，进程仍然需要创建自己的局部描述附表，（如wine这样的程序，），可以
使用modify_ldt()系统调用允许进程创建的自己的局部描述符表。
*/
int modify_ldt(int func, void *ptr, unsigned long bytecount);//local descriptor table (ldt) 

//On success, modify_ldt() returns either the actual number of bytes read (for reading) or 0 (for writing).
//On failure, modify_ldt() returns -1 and sets errno to indicate the error.