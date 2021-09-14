/**
 *	HUGETLBFS_UNLINKED_FD(3)                    
 *	Library Functions Manual                    HUGETLBFS_UNLINKED_FD(3)
 *
 *	NAME
 *	hugetlbfs_unlinked_fd,  hugetlbfs_unlinked_fd_for_size - Obtain a file descriptor for a new unlinked file
 *	in hugetlbfs
 *
 *	SYNOPSIS
 *	#include <hugetlbfs.h>
 *
 *	int hugetlbfs_unlinked_fd(void);
 *	int hugetlbfs_unlinked_fd_for_size(long page_size);
 */
int hugetlbfs_unlinked_fd(void);
int hugetlbfs_unlinked_fd_for_size(long page_size);
