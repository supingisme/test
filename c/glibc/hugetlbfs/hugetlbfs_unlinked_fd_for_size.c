#include <stdio.h>
#include <hugetlbfs.h>


int hugetlbfs_unlinked_fd_for_size(long page_size);

int main()
{

    
	int i;
	long pagesizes[64];
	int n_elem=64;
	int ret = getpagesizes(pagesizes, n_elem);

	printf("getpagesizes ret=%d.\n");

	for(i=0;i<ret;i++){
    	const char *path = hugetlbfs_find_path_for_size(pagesizes[i]);
        
        int fd = hugetlbfs_unlinked_fd_for_size(pagesizes[i]);
    
		printf("%s (%d)>> %ld. %ld kB, %ld MB\n", path, fd, pagesizes[i], pagesizes[i]/1024, pagesizes[i]/1024/1024);
	}
}




