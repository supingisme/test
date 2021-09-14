#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <stdlib.h>

//unlock a pseudoterminal master/slave pair
int unlockpt(int fd);

