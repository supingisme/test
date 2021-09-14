#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#include "log.h"
#include "dll.h"


int main()
{
	void *dp;
	char *err;
	char fname[20];
	dll p;
	debug();
	void (*init)(dll *p);
	void (*done)();
	printf("Input library name libmodule1.so or libmodule2.so .\n");
	printf("Input>> ");

	char tmp[20];
	scanf("%s", tmp);
	debug();

	//printf("Open file: %s\n", tmp);

	sprintf(fname, "./%s", tmp);

	dp = dlopen(fname, RTLD_LAZY);/*打开动态库。*/

	printf("Open file: %s\n", fname);

	if( NULL == dp) {
		printf("%s\n", dlerror());
		exit(1);
	}
	debug();
	init = dlsym(dp, "init");/*找到init函数的地址。*/
	init(&p);

	done = dlsym(dp, "done");
	done();

	printf("%s\n", p.name);

	return 0;
}


