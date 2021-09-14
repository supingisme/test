

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/* Prints the environment, one environment variable to a line, of the
 * process given by PID. */
/**
 *	[rongtao@localhost proc]$ ps
 *	PID TTY          TIME CMD
 *	141089 pts/0    00:00:01 bash
 *	234510 pts/0    00:00:00 ps
 *	[rongtao@localhost proc]$ ./a.out 141089
 *	USER=rongtao
 *	LOGNAME=rongtao
 *	HOME=/home/rongtao
 *	PATH=/usr/local/bin:/usr/bin
 *	MAIL=/var/mail/rongtao
 *	SHELL=/bin/bash
 *	SSH_CLIENT=10.170.6.24 61868 22
 *	SSH_CONNECTION=10.170.6.24 61868 10.170.6.66 22
 *	SSH_TTY=/dev/pts/0
 *	TERM=xterm
 *	DISPLAY=localhost:10.0
 *	XDG_SESSION_ID=11289
 *	XDG_RUNTIME_DIR=/run/user/1002
 *
 */
void print_process_environment (pid_t pid)
{
	int fd;
	char filename[24];
	char environment[8192];
	size_t length;
	char* next_var;
	/* Generate the name of the environ file for the process. */
	snprintf (filename, sizeof (filename), "/proc/%d/environ", (int) pid);
	/* Read the contents of the file. */
	fd = open (filename, O_RDONLY);
	length = read (fd, environment, sizeof (environment));
	close (fd);
	/* read does not NUL-terminate the buffer, so do it here. */
	environment[length] = '\0';
	/* Loop over variables. Variables are separated by NULs. */
	next_var = environment;
	while (next_var < environment + length) {
		/* Print the variable. Each is NUL-terminated, so just treat it
		 * like an ordinary string. */
		printf ("%s\n", next_var);
		/* Advance to the next variable. Since each variable is
		 * NUL-terminated, strlen counts the length of the next variable,
		 * not the entire variable list. */
		next_var += strlen (next_var) + 1;
	}
}
int main (int argc, char* argv[])
{
	pid_t pid = (pid_t) atoi (argv[1]);
	print_process_environment (pid);
	return 0;
}
