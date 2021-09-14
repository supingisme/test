
/*
 * daemon(3) implementation for systems lacking one.
 * Cobbled together from various daemon(3) implementations,
 * not intended to be general-purpose. */
#ifndef HAVE_DAEMON
int daemon(int nochdir, int noclose)
{
    pid_t pid = 0;
    pid_t sid = 0;
    int fd;

    /*
     * Ignore any possible SIGHUP when the parent process exits.
     * Note that the iperf3 server process will eventually install
     * its own signal handler for SIGHUP, so we can be a little
     * sloppy about not restoring the prior value.  This does not
     * generalize.
     */
    signal(SIGHUP, SIG_IGN);

    pid = fork();
    if (pid < 0) {
	    return -1;
    }
    if (pid > 0) {
	/* Use _exit() to avoid doing atexit() stuff. */
	_exit(0);
    }

    sid = setsid();
    if (sid < 0) {
	return -1;
    }

    /*
     * Fork again to avoid becoming a session leader.
     * This might only matter on old SVr4-derived OSs. 
     * Note in particular that glibc and FreeBSD libc 
     * only fork once.
     */
    pid = fork();
    if (pid == -1) {
	return -1;
    } else if (pid != 0) {
	_exit(0);
    }

    if (!nochdir) {
	chdir("/");
    }

    if (!noclose && (fd = open("/dev/null", O_RDWR, 0)) != -1) {
	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);
	if (fd > 2) {
	    close(fd);
	}
    }
    return (0);
}
#endif /* HAVE_DAEMON */
