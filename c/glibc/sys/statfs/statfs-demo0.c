
#include <sys/statfs.h>
#include <stdio.h>
 
int main()
{
   
    int i;
	struct statfs diskInfo;

    char *fss[] = {
        "/",
        "/boot",
        "/dev/shm",
        "/dev/mapper/centos-root",
        "/dev/vda1",
        "/dev/vdb",
        NULL,
    };
    
    for(i=0;fss[i]!=NULL;i++) {
        statfs(fss[i], &diskInfo);
        unsigned long long totalBlocks = diskInfo.f_bsize;
        unsigned long long totalSize = totalBlocks * diskInfo.f_blocks;
        size_t mbTotalsize = totalSize>>20;
        unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;
        size_t mbFreedisk = freeDisk>>20;
        printf ("%-15s  total=%8dMB, free=%8dMB\n", fss[i], mbTotalsize, mbFreedisk);
    }
    

//    statfs("/boot", &diskInfo);
//    totalBlocks = diskInfo.f_bsize;
//    totalSize = totalBlocks * diskInfo.f_blocks;
//    mbTotalsize = totalSize>>20;
//    freeDisk = diskInfo.f_bfree*totalBlocks;
//    mbFreedisk = freeDisk>>20;
//    printf ("/boot  total=%dMB, free=%dMB\n", mbTotalsize, mbFreedisk);
//
//    statfs("/dev/shm", &diskInfo);
//    totalBlocks = diskInfo.f_bsize;
//    totalSize = totalBlocks * diskInfo.f_blocks;
//    mbTotalsize = totalSize>>20;
//    freeDisk = diskInfo.f_bfree*totalBlocks;
//    mbFreedisk = freeDisk>>20;
//    printf ("/dev/shm  total=%dMB, free=%dMB\n", mbTotalsize, mbFreedisk);

    
    
	return 0;
}


