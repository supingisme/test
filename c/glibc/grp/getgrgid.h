#include <sys/types.h>
#include <grp.h>
//get group file entry

struct group *getgrnam(const char *name);

struct group *getgrgid(gid_t gid);

int getgrnam_r(const char *name, struct group *grp,
          char *buf, size_t buflen, struct group **result);

int getgrgid_r(gid_t gid, struct group *grp,
          char *buf, size_t buflen, struct group **result);

