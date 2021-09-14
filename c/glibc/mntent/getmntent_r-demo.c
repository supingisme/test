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
        printf("mnt_fsname:%s(%p) mnt_dir: %s mnt_type:%s mnt_opts: %s\n", 
                ent->mnt_fsname, ent->mnt_fsname, ent->mnt_dir, 
                ent->mnt_type, ent->mnt_opts);
        printf("%s\n", buf);
    }
    endmntent(aFile);
}


