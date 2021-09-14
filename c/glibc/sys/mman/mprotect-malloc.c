
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define debug() printf("%s:%d\n", __func__, __LINE__);


static int alloc_size;
static char* memory;


void segv_handler (int signal_number)
{
	printf ("memory accessed! signal_number(SIGSEGV) = %d\n", signal_number);

    //给这块内存读写权限，里厉害了老哥
	mprotect (memory, alloc_size, PROT_READ | PROT_WRITE);
}
int main ()
{
	int fd;
	struct sigaction sa;
	/**
	 *	Install segv_handler as the handler for SIGSEGV. 
	 *	
	 */
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &segv_handler;
	sigaction (SIGSEGV, &sa, NULL);
	
	/**
	 * Allocate one page of memory by mapping /dev/zero. Map the memory
	 * as write-only, initially. 
	 */
	alloc_size = getpagesize ();
	printf("alloc_size = %d\n", alloc_size);
    
#if 1
    /**
     *  malloc申请的内存不会在mprotect禁止写入的地方触发段错误！！？
     */
	memory = malloc(alloc_size);
#else
	fd = open ("/dev/zero", O_RDONLY);
	memory = mmap (NULL, alloc_size, PROT_WRITE, MAP_PRIVATE, fd, 0);
	close (fd);
#endif    
	debug();
    
	/* 
	 * Write to the page to obtain a private copy. 
	 */
	memory[0] = 0;

    debug();
    
	/* Make the memory unwritable. */
	//内存不可写
	mprotect (memory, alloc_size, PROT_NONE);

    debug();
    
	/* Write to the allocated memory region. */
    //这里写了这块内存，会触发段错误
	memory[0] = 1;
	memory[2] = 2;

    debug();
    
	/* All done; unmap the memory. */
    //这里读了这块内存，会触发段错误
	printf ("all done, memory[0] = %d\n", memory[0]);

    debug();
    
	munmap (memory, alloc_size);
	
	return 0;
}

