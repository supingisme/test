
#include <sys/mman.h>

//mlock, munlock, mlockall, munlockall - lock and unlock memory
int mlock(const void *addr, size_t len);
int munlock(const void *addr, size_t len);

//mlock, munlock, mlockall, munlockall - lock and unlock memory
int mlockall(int flags);
int munlockall(void);


SYSCALL_DEFINE2(mlock, unsigned long, start, size_t, len)
{
	return do_mlock(start, len, VM_LOCKED);
}

SYSCALL_DEFINE3(mlock2, unsigned long, start, size_t, len, int, flags)
{
	vm_flags_t vm_flags = VM_LOCKED;

	if (flags & ~MLOCK_ONFAULT)
		return -EINVAL;

	if (flags & MLOCK_ONFAULT)
		vm_flags |= VM_LOCKONFAULT;

	return do_mlock(start, len, vm_flags);
}

SYSCALL_DEFINE2(munlock, unsigned long, start, size_t, len)
{
	int ret;

	start = untagged_addr(start);

	len = PAGE_ALIGN(len + (offset_in_page(start)));
	start &= PAGE_MASK;

	if (down_write_killable(&current->mm->mmap_sem))
		return -EINTR;
	ret = apply_vma_lock_flags(start, len, 0);
	up_write(&current->mm->mmap_sem);

	return ret;
}

