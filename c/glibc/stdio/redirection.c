#include <stdio.h>
#include <stdlib.h>

int main()
{
	char line[256]  = {0};

	fprintf(stdout, "stdout.\n");
	fprintf(stderr, "stderr.\n");
	
	fscanf(stdin, "%s", line);
	fprintf(stdout, "stdout2\n");
	fprintf(stdout, "line = %s\n", line);


	return 0;
}
