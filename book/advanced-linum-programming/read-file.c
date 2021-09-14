/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 20日 星期四 08:47:53 CST. */


#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/* Read the contents of FILENAME into a newly allocated buffer. The
 * size of the buffer is stored in *LENGTH. Returns the buffer, which
 * the caller must free. If FILENAME doesn't correspond to a regular
 * file, returns NULL. */
char* read_file (const char* filename, size_t* length)
{
	int fd;
	struct stat file_info;
	char* buffer;
	/* Open the file. */
	fd = open (filename, O_RDONLY);
	/* Get information about the file. */
	fstat (fd, &file_info);
	*length = file_info.st_size;
	/* Make sure the file is an ordinary file. */
	if (!S_ISREG (file_info.st_mode)) {
		/* It's not, so give up. */
		close (fd);
		return NULL;
	}
	/* Allocate a buffer large enough to hold the file's contents. */
	buffer = (char*) malloc (*length);
	/* Read the file into the buffer. */
	read (fd, buffer, *length);
	/* Finish up. */
	close (fd);
	return buffer;
}
