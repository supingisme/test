#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>
#include <stdarg.h>


/**
 *  打印log debug信息
 *  作者： 荣涛
 *  时间： s2020年7月15日10:12:24
 */
typedef enum {
    LV_DEBUG,
    LV_INFO,
    LV_WARNING,
    LV_ERR,
}log_level_t;


#define debug(fmt...) ___debug_log(LV_DEBUG, __FILE__, __func__ ,__LINE__, fmt)
#define info(fmt...) ___debug_log(LV_INFO, __FILE__, __func__ ,__LINE__, fmt)
#define warning(fmt...) ___debug_log(LV_WARNING, __FILE__, __func__ ,__LINE__, fmt)
#define error(fmt...) ___debug_log(LV_ERR, __FILE__, __func__ ,__LINE__, fmt)


void set_log_level(log_level_t lv);
log_level_t get_log_level();


inline int ___debug_log(log_level_t level, char *file, const char *func, int line, char *fmt, ...);



#endif /*<__LOG_H>*/
