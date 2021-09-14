
NOTE:
	0. *** 一个遍历文件系统的代码库： fs-filesystem/fs_occupy/ ***
	1. *** Glibc检测文件系统修改记录： test/c/glibc/sys/fanotify ***
	2. *** Glibc检测文件修改操作： test/c/glibc/sys/inotify


获取文件系统挂载点，并根据挂载点查询文件系统的使用情况侧C语言程序

分别使用了如下的系统调用接口

setmntent
getmntent getmntent_r
endmntent

statfs


获取文件系统及其挂载点的程序代码如下：
	----------------------------------------------------------------------------
	#include <stdio.h>
	#include <stdlib.h>
	#include <mntent.h>

	struct mntent *getmntent_r(FILE *fp, struct mntent *mntbuf,
	                          char *buf, int buflen);

	int main(void)
	{
	    struct mntent *ent;
	    FILE *aFile;
	    struct mntent mntbuf;
	    char buf[512] = {0};
	    
	    ///proc/self/mountinfo

	    ///proc/mounts 或者是 /etc/mtab
	    aFile = setmntent("/proc/mounts", "r"); 
	    if (aFile == NULL) {
	        perror("setmntent");
	        exit(1);
	    }
	    while (NULL != (ent = getmntent_r(aFile, &mntbuf, buf, 512))) {
	        printf("mnt_fsname:%s mnt_dir: %s mnt_type:%s mnt_opts: %s\n", 
	                ent->mnt_fsname, ent->mnt_dir, 
	                ent->mnt_type, ent->mnt_opts);
	        printf("%s\n", buf);
	    }
	    endmntent(aFile);
	}
	----------------------------------------------------------------------------


根据挂载点计算文件系统使用情况的程序如下

	----------------------------------------------------------------------------

	#include <sys/statfs.h>
	#include <stdio.h>
	#include <string.h>

	int main()
	{
	   
	    int i;
		struct statfs diskInfo;

	    char *fss[] = {
	        "/",
	        "/dev",
	        "/dev/shm",

	        NULL,
	    };
	    printf("FS Total Free \n");
	    for(i=0;fss[i]!=NULL;i++) {
	        memset(&diskInfo, 0, sizeof(struct statfs));
	        
	        statfs(fss[i], &diskInfo);
	        
	        printf("%-15s %ld\t%ld\t",
	            fss[i],
	            diskInfo.f_blocks,		/* total data blocks in file system */
	            diskInfo.f_bfree		/* free blocks in fs */
	        );
				        
	        unsigned long long totalBlocks = diskInfo.f_bsize;
	        unsigned long long totalSize = totalBlocks * diskInfo.f_blocks;
	        size_t mbTotalsize = totalSize>>20;
	        unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;
	        size_t mbFreedisk = freeDisk>>20;
	        printf ("%8dMB\t%8dMB\t%.2lf%%\n", mbTotalsize, mbFreedisk,(mbTotalsize-mbFreedisk)*1.0/mbTotalsize*100.0);
	    }
	    
		return 0;
	}

	----------------------------------------------------------------------------




