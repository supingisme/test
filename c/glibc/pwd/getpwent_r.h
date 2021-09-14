#include <pwd.h>

//get password file entry
int getpwent_r(struct passwd *pwbuf, char *buf,
                size_t buflen, struct passwd **pwbufp);

//get password file entry
int fgetpwent_r(FILE *fp, struct passwd *pwbuf, char *buf,
                size_t buflen, struct passwd **pwbufp);

