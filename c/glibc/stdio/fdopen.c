#include <stdio.h>
#include <pthread.h>

int pipe_fd[2] = {0};

void *task_fn(void*arg)
{
	sleep(2);
	int cnt = 0;
	char buf[16] = {"Hello"};
	while(1)
	{
		cnt++;
		buf[5] = cnt;
		write(pipe_fd[1], buf, strlen(buf));
		sleep(1);
	}
}

int main()
{
		

	pipe(pipe_fd);

	pthread_t task;
	pthread_create(&task, NULL, task_fn, NULL);

	char buf[256] = {0};
	int len=0;

	while(1)
	{
		sleep(1);
		len = read(pipe_fd[0], buf, sizeof(buf));
		fprintf(stdout, "read: %s\n", buf);
	}

	
}
