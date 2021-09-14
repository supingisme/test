#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libintl.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>

#define die_errno(err) printf("%s\n", err);exit(0);
char *GIT_LOCALE_PATH = "";

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
void git_setup_gettext(void)
{
	const char *podir = getenv("GIT_TEXTDOMAINDIR");

	if (!podir)
		podir = GIT_LOCALE_PATH;
	bindtextdomain("git", podir);
	setlocale(LC_MESSAGES, "");
	setlocale(LC_TIME, "");
	init_gettext_charset("git");
	textdomain("git");
}
int main()
{
	sanitize_stdfds();	
	git_setup_gettext();



	return 0;
}
