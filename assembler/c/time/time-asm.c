#include <stdio.h>
#include <time.h>

int main()
{
	time_t tt;
	struct tm *t;
	asm volatile (
		"mov $0, %%ebx\n\t"		/* time(NULL) 的入参 NULL */
		"mov $0xd, %%eax\n\t"	/* time 的系统调用号 */
		"int $0x80\n\t"			/*  */
		"mov %%eax, %0\n\t"		/*  */
		: "=m" (tt)				/*  */
	);
	t = localtime(&tt);
	printf("time:%d\n", t->tm_year+1900);
}
