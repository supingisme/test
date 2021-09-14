#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signum) 
{
	pid_t pid, ppid;
	printf("catch signal.\nn");
	if((pid = fork())) {
		printf("pid %d, exit.\n", getpid());
		exit(1);
	} else if(pid < 0) {
		exit(1);	
	}
#if 0
	setsid();
	if((pid = fork())) {
		exit(1);
	} else if(pid < 0) {
		exit(1);
	}
#endif
	if (pid == 0) {
#if 0
		ppid = getppid();
		printf("ppid = %d\n", ppid);
		char cmd[64] = {0};
		sprintf(cmd, "kill -9 %d", ppid);
		system(cmd);
#endif
		system("./a.out");
		while(1) sleep(1);
	}
}

int main(int argc, char* argv[])
{
	signal(SIGINT, sig_handler);

	while(1) {
		sleep(1);
		printf("PID: %d\n", getpid());
	}
	return 0;
}
