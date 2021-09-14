
#include <sys/statfs.h>
#include <stdio.h>
#include <string.h>

#ifdef __rtoax_debug
struct statfs {
    __SWORD_TYPE f_type;    /* type of file system (see below) */
    __SWORD_TYPE f_bsize;   /* optimal transfer block size */
    fsblkcnt_t   f_blocks;  /* total data blocks in file system */
    fsblkcnt_t   f_bfree;   /* free blocks in fs */
    fsblkcnt_t   f_bavail;  /* free blocks available to
                               unprivileged user */
    fsfilcnt_t   f_files;   /* total file nodes in file system */
    fsfilcnt_t   f_ffree;   /* free file nodes in fs */
    fsid_t       f_fsid;    /* file system id */
    __SWORD_TYPE f_namelen; /* maximum length of filenames */
    __SWORD_TYPE f_frsize;  /* fragment size (since Linux 2.6) */
    __SWORD_TYPE f_spare[5];
};
#endif //__rtoax_debug

int main()
{
   
    int i;
	struct statfs diskInfo;

    char *fss[] = {
//        "/",
//        "/boot",
//        "/dev/shm",
//        "/dev/mapper/centos-root",
//        "/dev/vda1",
//        "/dev/vdb",
        "/",
        "/dev",
        "/dev/shm",
        "/run",
        "/sys/fs/cgroup",
        "/boot",
        "/work",
        "/run/user/42",
        "/run/user/1002",

        "/home",
        "/dev/sda1",
        "/run/user/0",
        
        "/dev/mapper/centos-root",
        "/dev/vda1",
        "/dev/vdb",

        NULL,
    };
    printf("FS Total Free \n");
    for(i=0;fss[i]!=NULL;i++) {
        memset(&diskInfo, 0, sizeof(struct statfs));
        
        statfs(fss[i], &diskInfo);
    #if 0
        printf("%-s\t%#16lx\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t[%d,%d]\t%ld\t%ld\t[%ld,%ld,%ld,%ld]\n",
            fss[i],
            diskInfo.f_type,            /* filesystem type number */
            diskInfo.f_bsize,       /* fundamental file system block size */
            diskInfo.f_blocks,      /* total data blocks in file system */
            diskInfo.f_bfree,       /* free blocks in fs */
            diskInfo.f_bavail,      /* free blocks avail to non-superuser */
            diskInfo.f_files,       /* total file nodes in file system */
            diskInfo.f_ffree,       /* free file nodes in fs */
            diskInfo.f_fsid,            /* file system id */
            diskInfo.f_fsid,            /* file system id */
            diskInfo.f_namelen,     /* free file nodes in fs */
            diskInfo.f_frsize,      /* free file nodes in fs */
            diskInfo.f_spare[0],        /* spare for later */
            diskInfo.f_spare[1],        /* spare for later */
            diskInfo.f_spare[2],        /* spare for later */
            diskInfo.f_spare[3],        /* spare for later */
            diskInfo.f_spare[4]     /* spare for later */
        );
    #elif 0
        printf("%-15s %#16lx\t%ld\t%ld\t%ld\t%ld\t",
            fss[i],
            diskInfo.f_type,			/* filesystem type number */
            diskInfo.f_bsize,		/* fundamental file system block size */
            diskInfo.f_blocks,		/* total data blocks in file system */
            diskInfo.f_bfree,		/* free blocks in fs */
            diskInfo.f_bavail		/* free blocks avail to non-superuser */
        );
    #else
        printf("%-15s %ld\t%ld\t",
            fss[i],
            diskInfo.f_blocks,		/* total data blocks in file system */
            diskInfo.f_bfree		/* free blocks in fs */
        );
    #endif

        
        unsigned long long totalBlocks = diskInfo.f_bsize;
        unsigned long long totalSize = totalBlocks * diskInfo.f_blocks;
        size_t mbTotalsize = totalSize>>20;
        unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;
        size_t mbFreedisk = freeDisk>>20;
        printf ("%8dMB\t%8dMB\t%.2lf%%\n", mbTotalsize, mbFreedisk,(mbTotalsize-mbFreedisk)*1.0/mbTotalsize*100.0);
    }
    
    
    
	return 0;
}



