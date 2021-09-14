#include <stdio.h>
#include <mcheck.h>
#include <malloc.h>
#include <stdlib.h>
/**
 * 定位内存泄漏
 */
/**
 *  检测内存泄漏
 *  
 *  文件 mtrace.log 内容如下：
 *  
    = Start
    @ ./a.out:[0x400674] + 0xd506d0 0x64
    @ ./a.out:[0x400684] - 0xd506d0
    @ ./a.out:[0x40068e] + 0xd50740 0x3e8
    @ ./a.out:[0x40069e] - 0xd50740
    @ ./a.out:[0x4006a8] + 0xd506d0 0x3e8
    @ ./a.out:[0x4006b8] - 0xd506d0
    = End
 *  
 *  每个内存操作都会对应一个trace，当不能free和malloc匹配时，即出现了内存泄漏
 */
static void test1_mtrace()
{
    mtrace();

	char *p = malloc(100);

	free(p);

	p = malloc(1000);
	free(p);
	p = malloc(1000);
	free(p);


	muntrace();
}

int main()
{
    setenv("MALLOC_TRACE", "./mtrace.log", 1);

	test1_mtrace();

	return 0;
}	

