//int execv(const char *path, char *const argv[]);

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <libgen.h>


void exe_reboot(const char *exe, char *const argv[])
{
	pid_t pid, ppid;
    if((pid = fork())) {
		printf("pid %d, exit.\n", getpid());
		exit(1);
	} else if(pid < 0) {
		exit(1);	
	}
#if 0    
    char *path = NULL;
    char EXE[1024] = {0};
    asprintf(&path, "/proc/%d/exe", getpid());
    readlink(path, EXE, 1024);
    char *dir = dirname(path);
    char *base = basename(path);
    chdir(dir);
#endif

	if (pid == 0) {
		execv(exe, argv);
		while(1) sleep(1);
	}
}


void sig_handler(int signum) 
{
	printf("catch signal.\nn");

    const char *exe="a.out";
    char *const argv[] = {NULL};
    
	exe_reboot(exe, argv);
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

