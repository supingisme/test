#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef char **ARGS;

#define debug() printf("%s:%d\n", __func__, __LINE__)

int fun(ARGS *args)
{
	static char *doc[] = {
		"rongtao",
		"sylincom",
		NULL,
	};
	debug();
	(*args) = malloc(3);
	(*args)[0] = malloc(64);
	(*args)[1] = malloc(64);
	(*args)[2] = malloc(64);
	debug();
	strcpy((*args)[0], doc[0]);debug();
	strcpy((*args)[1], doc[1]);debug();
	(*args)[2] = NULL;
	//strcpy(args[2], doc[2]);debug();
	return 0;
}

int main()
{
	char *doc[] = {
		"rongtao",
		"sylincom",
		NULL
	};
	debug();
	ARGS args;
	fun(&args);debug();
	printf("args: %s\n", args[0]);debug();
	

	return 0;
}
