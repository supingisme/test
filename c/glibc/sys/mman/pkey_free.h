

SYSCALL_DEFINE1(pkey_free, int, pkey)
{
	int ret;

	down_write(&current->mm->mmap_sem);
	ret = mm_pkey_free(current->mm, pkey);
	up_write(&current->mm->mmap_sem);

	/*
	 * We could provie warnings or errors if any VMA still
	 * has the pkey set here.
	 */
	return ret;
}

