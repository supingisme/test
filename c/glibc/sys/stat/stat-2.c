#include <stdio.h>
#include <sys/stat.h>
int main (int argc, char* argv[])
{
	const char* const filename = argv[1];
	struct stat buf;
	/* Get file information. */
	stat (filename, &buf);
	/* If the permissions are set such that the file’s owner can write
	 * to it, print a message. */
	if (buf.st_mode & S_IWUSR)
		printf ("Owning user can write `%s'.\n", filename);
	return 0;
}
