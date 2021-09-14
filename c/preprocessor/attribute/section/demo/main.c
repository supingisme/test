#include <stdio.h>
#include "common.h"



int _initdata boot = 0;

int  init_main1()
{
	printf("rongtao1\n");
}
int  init_main2()
{
	printf("rongtao2\n");
}

INIT(init_main1);
INIT(init_main2);

int main()
{
	printf("boot = %d\n", 0);
	do_initcalls();
}
