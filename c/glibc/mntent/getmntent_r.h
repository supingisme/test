/* GNU extension */
#include <mntent.h>

//The  reentrant getmntent_r() function is similar to getmntent(), 
//but stores the struct mount in the provided *mntbuf and stores the strings
//pointed to by the entries in that struct in the provided array buf of size buflen.
struct mntent *getmntent_r(FILE *fp, struct mntent *mntbuf,
                          char *buf, int buflen);
