/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */


#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags,
			                     int fd, off_t offset);
int munmap(void *addr, size_t length);

//See NOTES for information on feature test macro requirements.


int vm_munmap(unsigned long addr, size_t len)
{
	struct mm_struct *mm = current->mm;
	int ret;

	down_write(&mm->mmap_sem);
	ret = do_munmap(mm, addr, len, NULL);
	up_write(&mm->mmap_sem);
	return ret;
}
EXPORT_SYMBOL(vm_munmap);

SYSCALL_DEFINE2(munmap, unsigned long, addr, size_t, len)
{
	return vm_munmap(addr, len);
}


