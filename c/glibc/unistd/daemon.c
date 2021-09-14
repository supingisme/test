#include <unistd.h>

//daemon - run in the background
//int daemon(int nochdir, int noclose);

int main()
{
	daemon(1,1);

	while(1){
		printf("--->\n");
		sleep(1);
	}
}

