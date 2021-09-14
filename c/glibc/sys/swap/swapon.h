
#include <unistd.h>
#include <asm/page.h> /* to find PAGE_SIZE */
#include <sys/swap.h>

//start/stop swapping to file/device
//交换空间

//swapon()  sets  the swap area to the file or block device specified by path.  
//swapoff() stops swapping to the file or block device specified by path.
int swapon(const char *path, int swapflags);
//int swapoff(const char *path);

