#include <malloc.h>


struct mallinfo {
   int arena;     /* Non-mmapped space allocated (bytes) */
   int ordblks;   /* Number of free chunks */
   int smblks;    /* Number of free fastbin blocks */
   int hblks;     /* Number of mmapped regions */
   int hblkhd;    /* Space allocated in mmapped regions (bytes) */
   int usmblks;   /* Maximum total allocated space (bytes) */
   int fsmblks;   /* Space in freed fastbin blocks (bytes) */
   int uordblks;  /* Total allocated space (bytes) */
   int fordblks;  /* Total free space (bytes) */
   int keepcost;  /* Top-most, releasable space (bytes) */
};


//mallinfo - obtain memory allocation information
struct mallinfo mallinfo(void);
//The  mallinfo()  function  returns  a copy of a structure containing information about memory allocations
//performed by malloc(3) and related functions.  This structure is defined as follows:


//arena     The total amount of memory allocated by means other than mmap(2) (i.e., memory allocated on the heap).  This figure includes both in-use blocks and blocks on the free list.
//ordblks   The number of ordinary (i.e., non-fastbin) free blocks.
//smblks    The number of fastbin free blocks (see mallopt(3)).
//hblks     The  number of blocks currently allocated using mmap(2).  (See the discussion of M_MMAP_THRESH‐OLD in mallopt(3).)
//hblkhd    The number of bytes in blocks currently allocated using mmap(2).
//usmblks   The "highwater mark" for allocated space—that is, the maximum amount of  space  that  was  ever allocated.  This field is maintained only in nonthreading environments.
//fsmblks   The total number of bytes in fastbin free blocks.
//uordblks  The total number of bytes used by in-use allocations.
//fordblks  The total number of bytes in free blocks.
//keepcost  The  total  amount of releasable free space at the top of the heap.  This is the maximum number of bytes that could ideally (i.e., ignoring page alignment restrictions, and so on) be released by malloc_trim(3).
//
//arena:  通过mmap（2）以外的方式分配的内存总量（即，在堆上分配的内存）。该map包括使用中的块和空闲列表中的块。
//ordblks:  普通（即非fastbin）空闲块的数量。
//smblks:   fastbin空闲块的数量（请参阅mallopt（3））。
//hblks:  当前使用mmap（2）分配的块数。 （请参阅Mallopt（3）中有关M_MMAP_THRESH‐OLD的讨论。）
//hblkhd:  当前使用mmap（2）分配的块中的字节数。
//usmblks:  分配空间的“高水位标记”，即曾经分配的最大空间量。此字段仅在非线程环境中维护。
//fsmblks:   fastbin空闲块中的字节总数。
//uordblks:  使用中的分配所使用的字节总数。
//fordblks:  空闲块中的字节总数。
//keepcost:  堆顶部的可释放可用空间总量。这是malloc_trim（3）理想情况下可以释放的最大字节数（即，忽略页面对齐限制等）。

