#include <sys/time.h>
#include <sys/resource.h>

//get/set resource limits
int prlimit(pid_t pid, int resource, const struct rlimit *new_limit,
            struct rlimit *old_limit);

