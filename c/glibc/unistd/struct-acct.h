#define ACCT_COMM 16

typedef u_int16_t comp_t;

struct acct {
    char ac_flag; /* 记账标记 */
    u_int16_t ac_uid; /* 记账用户 ID */
    u_int16_t ac_gid; /* 记账组 ID */
    u_int16_t ac_tty; /* 控制终端 */
    u_int32_t ac_btime; /* 进程创建时间
    (从开机起的秒数) */
    comp_t ac_utime; /* 用户 CPU 时间 */
    comp_t ac_stime; /* 系统 CPU 时间 */
    comp_t ac_etime; /* 流失的时间 */
    comp_t ac_mem; /* 平均内存用量 (kB) */
    comp_t ac_io; /* Characters transferred (未使用) */
    comp_t ac_rw; /* 读写的块 (未使用) */
    comp_t ac_minflt; /* Minor page faults */
    comp_t ac_majflt; /* Major page faults */
    comp_t ac_swaps; /* Number of swaps (unused) */
    u_int32_t ac_exitcode; /* 进程终止状态
    (参看 wait(2)) */
    char ac_comm[ACCT_COMM+1];
    /* 命令名 (执行文件名；以0结尾) */
    char ac_pad[X]; /* 填充字节 */
};

enum { /* 在 ac_flag 域可以设置的位 */
    AFORK = 0x01, /* 调用 fork 之后，但还没有调用 exec */
    ASU = 0x02, /* 使用超级用户权限 */
    ACORE = 0x08, /* 核心转储 */
    AXSIG = 0x10 /* 由信号杀死 */
};

