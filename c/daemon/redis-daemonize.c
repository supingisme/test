#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

void daemonize(void) {
    int fd;

    if (fork() != 0) exit(0); /* parent exits */
    setsid(); /* create a new session */

#if 1
	while(1) {
		printf("[daemon:%d] is running.\n",getpid());
		sleep(1);
	}

#else
    /* Every output goes to /dev/null. If Redis is daemonized but
     * the 'logfile' is set to 'stdout' in the configuration file
     * it will not log at all. */
    if ((fd = open("/dev/null", O_RDWR, 0)) != -1) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) close(fd);
    }
#endif
}

int main()
{
	daemonize();

	//下面这些将不会打印
	while(1) {
		printf("[%d] is running.\n",getpid());
		sleep(1);
	}
}
