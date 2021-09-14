#include <stdio.h>

int main()
{
	char cmd[123] = {0};

	FILE *fp = fopen("a.txt", "r");


	while(fgets(cmd, 123, fp))
		printf("cmd = %s\n", cmd);

	fclose(fp);

	return 0;
}
