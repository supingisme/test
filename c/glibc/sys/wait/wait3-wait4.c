

/**
 *	NAME
 *	wait3, wait4 - wait for process to change state, BSD style
 *
 *	SYNOPSIS
 *	#include <sys/types.h>
 *	#include <sys/time.h>
 *	#include <sys/resource.h>
 *	#include <sys/wait.h>
 *
 *	pid_t wait3(int *status, int options,
 *	struct rusage *rusage);
 *
 *	pid_t wait4(pid_t pid, int *status, int options,
 *	struct rusage *rusage);
 *	
 */

#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *	Cleaning Up Children Asynchronously
 *	If you’re using a child process simply to exec another program, it’s fine to call wait
 *	immediately in the parent process, which will block until the child process completes.
 *	But often, you’ll want the parent process to continue running, as one or more children
 *	execute synchronously. How can you be sure that you clean up child processes that
 *	have completed so that you don’t leave zombie processes, which consume system
 *	resources, lying around?
 *	One approach would be for the parent process to call wait3 or wait4 periodically,
 *	to clean up zombie children. Calling wait for this purpose doesn’t work well because,
 *	if no children have terminated, the call will block until one does. However, wait3 and
 *	wait4 take an additional flag parameter, to which you can pass the flag value WNOHANG.
 *	With this flag, the function runs in nonblocking mode—it will clean up a terminated
 *	child process if there is one, or simply return if there isn’t.The return value of the call
 *	is the process ID of the terminated child in the former case, or zero in the latter case.
 *	A more elegant solution is to notify the parent process when a child terminates.
 *	There are several ways to do this using the methods discussed in Chapter 5,
 *	“Interprocess Communication,” but fortunately Linux does this for you, using signals.
 *	When a child process terminates, Linux sends the parent process the SIGCHLD signal.
 *	The default disposition of this signal is to do nothing, which is why you might not
 *	have noticed it before.
 *	Thus, an easy way to clean up child processes is by handling SIGCHLD. Of course,
 *	when cleaning up the child process, it’s important to store its termination status if this
 *	information is needed, because once the process is cleaned up using wait, that information
 *	is no longer available. Listing 3.7 is what it looks like for a program to use a
 *	SIGCHLD handler to clean up its child processes.
 */

sig_atomic_t child_exit_status;
void clean_up_child_process (int signal_number)
{
	/* Clean up the child process. */
	int status;
	wait (&status);
	/* Store its exit status in a global variable. */
	child_exit_status = status;
}
int main ()
{
	/* Handle SIGCHLD by calling clean_up_child_process. */
	struct sigaction sigchld_action;
	memset (&sigchld_action, 0, sizeof (sigchld_action));
	sigchld_action.sa_handler = &clean_up_child_process;
	sigaction (SIGCHLD, &sigchld_action, NULL);
	/* Now do things, including forking a child process. */
	/* ... */
	return 0;
}
