/* NAME
 * msync - synchronize a file with a memory map
 *
 * SYNOPSIS */
#include <sys/mman.h>

int msync(void *addr, size_t length, int flags);

/**
 * DESCRIPTION
 * 
 * msync()  flushes changes made to the in-core copy of a file that was mapped into memory using
 * mmap(2) back to disk.  Without use of this call there is no guarantee that changes are  writ‐
 * ten  back  before  munmap(2) is called.  To be more precise, the part of the file that corre‐
 * sponds to the memory area starting at addr and having length length is updated.
 *
 * The flags argument may have the bits MS_ASYNC, MS_SYNC, and MS_INVALIDATE set, but  not  both
 * MS_ASYNC  and  MS_SYNC.  MS_ASYNC specifies that an update be scheduled, but the call returns
 * immediately.  MS_SYNC asks for an update and waits for it to complete.  MS_INVALIDATE asks to
 * invalidate other mappings of the same file (so that they can be updated with the fresh values
 * just written).
 *  
 */
