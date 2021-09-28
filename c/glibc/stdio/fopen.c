#include <stdio.h>
#include <errno.h>
#include <string.h>

FILE *fp = NULL;

int main()
{
	fp = fopen("libcare-cc.log", "w");

	int i = 10;
	
	while(i--) {
		int ret = fprintf(fp, "hello\n");
		fflush(fp);
		perror("fprintf");
		fprintf(stdout, "ret = %d\n", ret);
		sleep(1);
	}
	return 0;
}
