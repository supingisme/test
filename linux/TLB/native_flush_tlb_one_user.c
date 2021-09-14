#include <stdio.h>

void native_flush_tlb_one_user(unsigned long addr)
{
	//...
	asm volatile("invlpg (%0)" ::"r" (addr) : "memory");
	//...
}

int main(int argc, char *argv[])
{
	int a = 10000000;

	while(a--);

	/**
	 *	为啥这里会段错误
	 *	可能这里应该为 物理地址
	 */
	native_flush_tlb_one_user(a);
}
