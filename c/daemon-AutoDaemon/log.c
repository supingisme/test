#include <libgen.h>

#include "log.h"

static log_level_t log_level = LV_ERR; //只显示错误信息



void set_log_level(log_level_t lv)
{
    if(lv >= LV_DEBUG && lv <= LV_ERR)
        log_level = lv;
}

log_level_t get_log_level()
{
    return log_level;
}


inline int ___debug_log(log_level_t level, char *file, const char *func, int line, char *fmt, ...)
{
    if(log_level>level)
        return 0;

    va_list av;
    va_start(av, fmt);

    switch(level) {
        case LV_INFO:
            printf(" [%s INFO%s][%s:%s:%d]: ","\033[1;36m","\033[0m", basename(file), func, line);
            break;
        case LV_WARNING:
            printf(" [%s WARN%s][%s:%s:%d]: ","\033[1;35m","\033[0m", basename(file), func, line);
            break;
        case LV_ERR:
            printf(" [%sERROR%s][%s:%s:%d]: ","\033[1;31m","\033[0m", basename(file), func, line);
            break;
        case LV_DEBUG:
            printf(" [%sDEBUG%s][%s:%s:%d]: ","\033[1m",   "\033[0m", basename(file), func, line);
            break;
    }
    
    int i = vprintf(fmt, av);

    va_end(av);

    return i;
}

