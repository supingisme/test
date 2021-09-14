#define _BSD_SOURCE             /* See feature_test_macros(7) */
#include <sys/types.h>

//makedev, major, minor - manage a device number

//dev_t makedev(int maj, int min);

unsigned int major(dev_t dev);
//unsigned int minor(dev_t dev);

