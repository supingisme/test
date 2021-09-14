#include <sys/types.h>
#include <grp.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    char             *_group = "root";
    struct passwd    *pwd;
    struct group     *grp;

    gid_t gr_gid;

    grp = getgrnam(_group);
    if (grp == NULL) {
        printf("getgrnam(\"%s\") failed\n", _group);

        switch(errno) {
            case EINTR://  A signal was caught.
                printf("A signal was caught.\n");
                break;
            case EIO://    I/O error.
                printf("I/O error.\n");
                break;
                
            case EMFILE:// The maximum number (OPEN_MAX) of files was open already in the calling process.
                printf("The maximum number (OPEN_MAX) of files was open already in the calling process.\n");
                break;
                
            case ENFILE:// The maximum number of files was open already in the system.
                printf("The maximum number of files was open already in the system.\n");
                break;
                
            case ENOMEM:// Insufficient memory to allocate group structure.
                printf("Insufficient memory to allocate group structure.\n");
                break;
                
            case ERANGE:// Insufficient buffer space supplied.
                printf("Insufficient buffer space supplied.\n");
                break;
        }
    
        return -1;
    }

    gr_gid = grp->gr_gid;

    if (initgroups("rongtao", gr_gid) == -1) {
        printf("initgroups(%s, %d) failed\n","rongtao", gr_gid);
        switch(errno) {
            case ENOMEM://  Insufficient memory to allocate group information structure.
                printf("Insufficient memory to allocate group information structure.\n");
                break; 

            case EPERM://  The calling process has insufficient privilege.  
                        //See the underlying system call setgroups(2).
                printf("The calling process has insufficient privilege.\n");
                break; 
        }
    }
    
}
