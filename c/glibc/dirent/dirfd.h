#include <sys/types.h>
#include <dirent.h>

int dirfd(DIR *dirp);

//Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//dirfd():
//_BSD_SOURCE || _SVID_SOURCE || /* Since glibc 2.10: */
//	(_POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700)

