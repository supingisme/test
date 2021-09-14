#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <stdlib.h>

//grantpt - grant access to the slave pseudoterminal
//允许接入slave伪终端
int grantpt(int fd);
//When successful, grantpt() returns 0.  Otherwise, it returns -1 and sets errno appropriately.

