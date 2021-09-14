#include <grp.h>

//get list of groups to which a user belongs
int getgrouplist(const char *user, gid_t group,
                 gid_t *groups, int *ngroups);

