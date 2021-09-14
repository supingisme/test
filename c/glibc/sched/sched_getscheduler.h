#include <sched.h>

int sched_setscheduler(pid_t pid, int policy,
                      const struct sched_param *param);

int sched_getscheduler(pid_t pid);

struct sched_param {
   ...
   int sched_priority;
   ...
};

