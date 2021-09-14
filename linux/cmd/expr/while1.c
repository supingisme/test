#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sinum){
	switch(sinum) {
		case SIGINT:
			printf("Catch Ctrl+c Signal.\n");
			exit(1);
		default:
			break;
	}
}

int main()
{
	signal(SIGINT, sig_handler);

	while(1);

	return 0;
}
