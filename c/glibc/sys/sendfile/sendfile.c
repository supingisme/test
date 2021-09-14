

/**
 *	The sendfile system call provides an efficient mechanism for copying data from one file
 *	descriptor to another. The file descriptors may be open to disk files, sockets, or other devices.
 *	Typically, to copy from one file descriptor to another, a program allocates a fixed-size buffer,
 *	copies some data from one descriptor into the buffer, writes the buffer out to the other descriptor,
 *	and repeats until all the data has been copied. This is inefficient in both time and space because it
 *	requires additional memory for the buffer and performs an extra copy of the data into that buffer.
 *	Using sendfile, the intermediate buffer can be eliminated. Call sendfile, passing the file
 *	descriptor to write to; the descriptor to read from; a pointer to an offset variable; and the number of
 *	bytes to transfer. The offset variable contains the offset in the input file from which the read should
 *	start (0 indicates the beginning of the file) and is updated to the position in the file after the transfer.
 *	The return value is the number of bytes transferred. Include <sys/sendfile.h> in your program if
 *	it uses sendfile.
 *	The program in Listing 8.10 is a simple but extremely efficient implementation of a file copy.
 *	When invoked with two filenames on the command line, it copies the contents of the first file into a
 *	file named by the second. It uses fstat to determine the size, in bytes, of the source file.
 */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/**
 *	两个文件描述符之间指向的文件的拷贝
 */
int main (int argc, char* argv[])
{
	int read_fd;
	int write_fd;
	struct stat stat_buf;
	off_t offset = 0;

    if(argc<3) {
        printf("%s [file-in] [file-out]\n", argv[0]);
        exit(1);
    }
    
	/* Open the input file. */
	read_fd = open (argv[1], O_RDONLY);
	/* Stat the input file to obtain its size. */
	fstat (read_fd, &stat_buf);
	/* Open the output file for writing, with the same permissions as the
	 * source file. */
	write_fd = open (argv[2], O_WRONLY | O_CREAT, stat_buf.st_mode);
	/* Blast the bytes from one file to the other. */
	/**
	 *	NOTICE:两个文件描述符之间进行复制（file、socket、devices）
	 *	[rongtao@localhost sendfile]$ gcc sendfile.c 
	 *	[rongtao@localhost sendfile]$ rm sendfile.out 
	 *	[rongtao@localhost sendfile]$ ./a.out sendfile.in sendfile.out
	 *	[rongtao@localhost sendfile]$ more sendfile.out
	 *
	 */
	sendfile (write_fd, read_fd, &offset, stat_buf.st_size);

    printf("sendfile: offset:%d, st_size:%d\n", offset, stat_buf.st_size);
    
	/* Close up. */
	close (read_fd);
	close (write_fd);
	return 0;
}
