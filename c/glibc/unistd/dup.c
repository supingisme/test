#include <stdio.h>
#include <string.h>
#include <unistd.h>

int demo1()
{
	int dup_stdout = dup(fileno(stdout));
	printf("dup_stdout %d\n", dup_stdout);

	char line[256] =  {"helloworld.\n"};
	write(dup_stdout, line, strlen(line));

	return 0;
}

int demo2()
{
	FILE *fp = fopen("dup.txt", "w");
	//FILE *fp = fopen("dup2.txt", "r");
	fprintf(fp, "-------\n");
	fprintf(fp, "-------\n");
	dup2(fileno(fp), fileno(stdout));
	//dup2(fileno(stdout), fileno(fp));
	fprintf(fp, "-------\n");
	//FILE *fp2 = fopen("dup2.txt", "r");
	//dup2(fileno(fp), fileno(fp2));
	fprintf(fp, "-------\n");

	fclose(fp);
}

int main()
{
	demo2();
}
