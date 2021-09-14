#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdlib.h>

int ptsname_r(int fd, char *buf, size_t buflen);

