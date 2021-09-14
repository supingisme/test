#include <stdio.h>
#include <time.h>

void init_deamon();

int main()
{
	FILE *fp;
	time_t t;

	init_deamon();
	while(1)
	{
		sleep(60);//每隔一分钟向test.log报告运行状态
		if((fp=fopen("test.log", "a")) >= 0)
		{
			t = time(0);
			fprintf(fp, "I'm here at %s\n", asctime(localtime(&t)));
			fclose(fp);
		}
	}
}
