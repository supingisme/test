#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	while(1) {
		printf("PID %d, PPID %d.\n", getpid(), getppid());
		sleep(1);
	}
}
