#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int gval = 8;//gval是共享的

void funcb(int *x, int *y, int z)//z是线程私有，z-i
{
	static int sv;//静态变量，共享的，在内存中只有一份，所以会引起冲突
	int u;//自变量，线程私有的
	u = (*y)*gval;//y本身是私有变量，其指向私有内存temp，
	*x = u + z;//x本身是私有的指针变量，但其指向的内存空间是共享的，私有指针指向共享内存
}

void funca(int *a, int n)//a和n是共享的
{
	int i;//循环控制变量，所以线程私有
	int cc = 9;//在并行化语句外声明，是共享的
	#pragma omp parallel for
	for(i = 0; i < n; i ++){
		
		int temp = cc;//并行化语句内部声明，是线程私有的
		funcb(&a[i], &temp, i);
	}
}

void main(int argc, char *argv[])
{
	int n = 10;
	int *a = malloc(sizeof(int)*n);
	funca(a,n);
}
