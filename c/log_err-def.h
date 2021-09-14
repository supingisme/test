#define log_err(fmt, ...)               \
    fprintf(stderr,                     \
        "ERROR: %s(%d): " fmt "\n",     \
        __FILE__,                       \
        __LINE__, ##__VA_ARGS__)
