
/* if any standard file descriptor is missing open it to /dev/null */
void sanitize_stdfds(void)
{
	int fd = open("/dev/null", O_RDWR, 0);
	while (fd != -1 && fd < 2)
		fd = dup(fd);
	if (fd == -1)
		die_errno("open /dev/null or dup failed");
	if (fd > 2)
		close(fd);
}

int daemonize(void)
{
#ifdef NO_POSIX_GOODIES
	errno = ENOSYS;
	return -1;
#else
	switch (fork()) {
		case 0:
			break;
		case -1:
			die_errno("fork failed");
		default:
			exit(0);
	}
	if (setsid() == -1)
		die_errno("setsid failed");
	close(0);
	close(1);
	close(2);
	sanitize_stdfds();
	return 0;
#endif
}

