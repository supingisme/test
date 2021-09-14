#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct msg {
    int type;
    int code;
    int len;
};

/* Read characters from the pipe and echo them to stdout. */
void read_from_pipe (int file)
{
	FILE *stream; 
	int c;
	stream = fdopen (file, "r");
	//while ((c = fgetc (stream)) != EOF)
	//	putchar (c);

    struct msg msg;
    for(;;)
    {
        if(read(fileno(stream), &msg, sizeof(msg)))
        {
            printf("%d, %d, %d\n", msg.type, msg.code, msg.len);
        }
    }
	fclose (stream);
}
/* Write some random text to the pipe. */
void write_to_pipe (int file)
{
	FILE *stream;
	stream = fdopen (file, "w");
    
    struct msg msg = {
        .type = 1,
        .code = 3,
        .len = 100,
    };
    
    write(fileno(stream), &msg, sizeof(msg));
    sleep(2);
    write(fileno(stream), &msg, sizeof(msg));

    sleep(10000);
	fclose (stream);
}
int main (void)
{
	pid_t pid;
	int mypipe[2];
	/* Create the pipe. */
	if (pipe (mypipe))
	{
		fprintf (stderr, "Pipe failed.\n");
		return EXIT_FAILURE;
	}
	/* Create the child process. */
	pid = fork ();
	if (pid == (pid_t) 0)
	{
		/* This is the child process.
		 * Close other end frst. */
		close (mypipe[1]);
		read_from_pipe (mypipe[0]);
		return EXIT_SUCCESS;
	}
	else if (pid < (pid_t) 0)
	{
		/* The fork failed. */
		fprintf (stderr, "Fork failed.\n");
		return EXIT_FAILURE;
	}
	else
	{
		/* This is the parent process.
		 * Close other end frst. */
		close (mypipe[0]);
		write_to_pipe (mypipe[1]);
		return EXIT_SUCCESS;
	}
}
