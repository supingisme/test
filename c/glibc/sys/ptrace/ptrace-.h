#include <sys/ptrace.h>

////读取子进程系统调用参数
long ptrace(enum __ptrace_request request, pid_t pid,
           void *addr, void *data);

