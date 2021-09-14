#include <stdio.h>

#if 0
#define debug() printf("%s:%d\n", __func__, __LINE__)
#else
#define debug()
#endif

#if 1
#define info(fmt...) printf(fmt)
#else
#define info(fmt...)
#endif

int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("usage: %s key1 key2\n", argv[0]);
		return -1;
	}
	char cmd[256] = {0};
	char line[256] = {0};

	sprintf(cmd, "ps -ef| grep %s | grep %s | awk '{print $2}'", argv[1], argv[2]);
	//sprintf(cmd, "ps -ef| grep %s | grep %s", argv[1], argv[2]);
	info("%s\n", cmd);

	debug();

	FILE *fp = popen(cmd, "r");

	debug();

	while(fgets(line, 256, fp))
	{
		printf("%s\n", line);
		if(500==atoi(argv[2]))
		{
			printf("Find pid 500\n");
			break;
		}
	}

	fclose(fp);

	return 0;
}
