#include <stdio.h>
#include <malloc.h>

typedef int (*set_fn)(int argc, void *argv[]);

struct set_node {
	set_fn set;
	int argc;
	void **argv;
}set;

void set_register(set_fn fn, int argc, void **argv)
{
	set.set = fn;
	set.argc = argc;
	set.argv = argv;
}

void set_call()
{
	set.set(set.argc, set.argv);
}

int myset(int argc, void *argv[])
{
	int i;
	for(i=0;i<argc;i++)
		printf("%s.\n", (char*)argv[i]);
}

int main()
{
	char *ss[] = {
		"rong", "tao"
	};
	set_register(myset, 2, (void**)ss);
	set_call();
}
