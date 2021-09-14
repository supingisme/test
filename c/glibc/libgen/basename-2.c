#include <stdio.h>
#include <libgen.h>

int main()
{
	char name[256] = {"Hello/adsf/adsf/a/df/Name"};
	char *ps = basename(name);

	printf("name = %s\n", name);
	printf("basename = %s\n", ps);

	printf("strlen = %d\n", strlen(""));
}
