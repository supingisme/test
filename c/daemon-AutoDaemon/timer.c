#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>
#include <unistd.h>
#include <malloc.h>
#include <stdbool.h>

#include "log.h"
#include "timer.h"

#ifndef _unused
#define _unused  __attribute__((unused))
#endif


pthread_t timer_routine;
LIST_HEAD(timer_list);
pthread_mutex_t timer_list_lock = PTHREAD_MUTEX_INITIALIZER;


#define CRTL_GT 1
#define CRTL_EQ 0
#define CRTL_LT (-1)

inline int timeval_cmp(struct timeval *in, struct timeval *in2)
{
    if(in->tv_sec > in2->tv_sec) {
        return CRTL_GT;
    } else if(in->tv_sec == in2->tv_sec) {
        if( in->tv_usec > in2->tv_usec ) {
            return CRTL_GT;
        } else if (in->tv_usec == in2->tv_usec) {
            return CRTL_EQ;
        } else {
            return CRTL_LT;
        }
    } else {
        return CRTL_LT;
    } 
    return CRTL_EQ;
}

inline void timeval_add(struct timeval *in, struct timeval *in2, struct timeval *out)
{
    out->tv_sec = in->tv_sec + in2->tv_sec + (in->tv_usec+in2->tv_usec)/1000000;
	out->tv_usec = (in->tv_usec+in2->tv_usec)%1000000;
}

inline int timeval_subabs(struct timeval *in1, struct timeval *in2, struct timeval *out)
{
    time_t in1Sec = in1->tv_sec;
    time_t in2Sec = in2->tv_sec;
    long in1uSec = in1->tv_usec;
    long in2uSec = in2->tv_usec;

    int cmp = timeval_cmp(in1, in2);
    if(cmp == CRTL_GT) {
        out->tv_usec = in1uSec+((in1uSec<in2uSec)?1000000:0) - in2uSec;
        out->tv_sec = in1Sec + ((in1uSec<in2uSec)?-1:0) - in2Sec;
    } else if(cmp == CRTL_EQ) {
        out->tv_sec = 0;
	    out->tv_usec = 0;
    } else if(cmp == CRTL_LT) {
        out->tv_usec = in2uSec+((in2uSec<in1uSec)?1000000:0) - in1uSec;
        out->tv_sec = in2Sec + ((in2uSec<in1uSec)?-1:0) - in1Sec;
    }
    
    return cmp;
}

static long int _unused sub_timeval_usec(struct timeval *t1, struct timeval *t2) {
    static struct timeval out;
    timeval_subabs(t1, t2, &out);
    return out.tv_sec*1000000 + out.tv_usec;
}
/* ?????????????????????-??????????????? */
inline static struct timer_node * get_timer_byid(unsigned long int timeid)
{
    /* ???????????? */
    if(((unsigned long int)0==(unsigned long int)timeid)) {
        warning("wrong params error. timeid=%ld\n", timeid);
        return NULL;
    }

    struct timer_node *__list_ite_timer = NULL;
    struct timer_node *_unused __list_ite_next_timer = NULL;
    
    /* ????????????????????? */
    list_for_each_entry_safe(__list_ite_timer,__list_ite_next_timer, &timer_list, list) {
//        __crtl_dbg(">>> %lx, %lx\n", __list_ite_timer->timer_id, timeid);
        if( __list_ite_timer->timerid == timeid ) {
            return __list_ite_timer;
        }
        if(list_is_last(&__list_ite_timer->list, &timer_list)) {
//            __crtl_dbg("Last NOde no OK.\n");
            return NULL;
        } 
        if( __list_ite_next_timer->timerid == timeid ) {
            return __list_ite_next_timer;
        } else {
            __list_ite_timer = __list_ite_next_timer;
        }
    }
    debug("Not exist.\n");
    return NULL;
}


/* ????????????????????????????????? */
inline static int  timer_add_to_list(struct timer_node *__insert_timer)
{
    struct timer_node *__list_ite_timer = NULL;
    struct timer_node *_unused  __list_ite_next_timer = NULL;
    struct timer_node *_unused  __small_timer = NULL;
    struct timer_node *_unused  __big_timer = NULL;

    struct timeval time_interval = {0, 0};
    
    /**
     *  1.Find the location of insert timer
     *
     *      __small_timer   __big_timer
     *
     *  2.Insert new timer
     *      __small_timer  __insert_timer  __big_timer
     */
    
    /* ????????????,???????????? */
    if(list_empty(&timer_list)) {
        list_add_tail(&__insert_timer->list, &timer_list);
//        crtl_rbtree_insert(__crtl_timers_tree, __insert_timer, sizeof(struct crtl_timer_struct));
    /* ???????????????,???????????? */
    } else {
        list_for_each_entry_safe(__list_ite_timer,__list_ite_next_timer, &timer_list, list) {
            
            int cmp = timeval_subabs(&__list_ite_timer->timeout, 
                                           &__insert_timer->timeout, 
                                           &time_interval);
            if(cmp == CRTL_GT) {
                struct timer_node * __list_prev_timer = list_prev_entry(__list_ite_timer, list);
                list_add(&__insert_timer->list, &__list_prev_timer->list);
                break;
            } 
            if(list_is_last(&__list_ite_timer->list, &timer_list)) {
                list_add(&__insert_timer->list, &__list_ite_timer->list);
                break;
            
            /* ???????????????????????????????????? ???????????? __list_ite_next_timer */
            } else {
            
                /* ?????????????????????????????????????????????????????????*/
                if(cmp == CRTL_EQ) {
                    list_add(&__insert_timer->list, &__list_ite_timer->list);
                    break;
                
                /* ???????????????????????????????????????????????????????????????????????? */
                } else if(cmp == CRTL_LT) {
                    int cmp_next = timeval_subabs(&__list_ite_next_timer->timeout, 
                                                        &__insert_timer->timeout, 
                                                        &time_interval);
                    /* ???????????????????????????????????????????????? */
                    if(cmp_next == CRTL_GT || cmp_next == CRTL_EQ) {
                        list_add(&__insert_timer->list, &__list_ite_timer->list);
                        break;
                    /* ???????????????????????????????????? */
                    } else if(cmp_next == CRTL_LT) {
                        continue;
                    }
                }
            }
    	}
    }
    
    return 0;
}

static void * sched_timer_list(void *arg) {
    struct timeval currentTime, time_interval;
    struct timer_node *__this_timer = NULL, _unused *next_timer, *__list_ite_timer, *__list_ite_next_timer;
    
    while(1) {
        usleep(1000);
        gettimeofday(&currentTime, NULL);
    
        pthread_mutex_lock(&timer_list_lock);
        if(list_empty(&timer_list)) {
            pthread_mutex_unlock(&timer_list_lock);
            continue;
        }
#if 0
        list_for_each_entry_safe(__this_timer, next_timer, &timer_list, list) {
            
            diff_usec = sub_timeval_usec(&__this_timer->timeout, &current);
            if(diff_usec < 10000 ) {
                __this_timer->callback(__this_timer->arg);
                list_del(&__this_timer->list);
                if(__this_timer->isloop) {
                    
                }
            }
            __this_timer = next_timer;
        }
#else
        
        /* ????????????????????? */
        list_for_each_entry_safe(__list_ite_timer,__list_ite_next_timer, &timer_list, list) {

            __this_timer = __list_ite_timer;
            if(!list_is_last(&__list_ite_timer->list, &timer_list)) {
                __list_ite_timer = __list_ite_next_timer;
            }
                        
            /* ????????????????????????????????????????????? */
            timeval_subabs(&__this_timer->timeout, &currentTime,  &time_interval);

            /* ??????????????????????????????????????????????????? */
            if(10000 >= time_interval.tv_sec*1000000+time_interval.tv_usec) {
                
                /* ?????? */
                __this_timer->callback(__this_timer->arg);

                /* ????????????????????????????????? */
                list_del_init(&__this_timer->list);
//                crtl_rbtree_delete(__crtl_timers_tree, __this_timer);
                /* ???????????????????????? */
                if(__this_timer->isloop) {
                    
                    /* ??????????????????:?????????????????????GetTimeofDay?????? */
                    timeval_add(&currentTime, &__this_timer->interval, 
                                                    &__this_timer->timeout);
                    
                    timer_add_to_list(__this_timer);
                    
                } else {
                    free(__this_timer);
                }
                
            }else { /* ???????????????????????????????????????????????????????????????????????? */
                break;
            }
        }

#endif
        pthread_mutex_unlock(&timer_list_lock);
    }
    
    return NULL;
}




/* ??????????????? */
unsigned long int timer_new(bool is_loop, void (*callback)(void *arg), void *arg, long sec, long usec)
{
    unsigned long int timerid = 0;
    
    struct timer_node *__timer = malloc(sizeof(struct timer_node));

    timerid = __timer->timerid = (unsigned long int)__timer;

    __timer->isloop = is_loop;

    struct timeval currentTime = {0,0};

    /* ??????????????????????????? */
    __timer->interval.tv_sec = sec;
    __timer->interval.tv_usec = usec;

    /* ?????????????????? */
    gettimeofday(&currentTime, NULL);
    
    /* ??????????????????:?????????????????????GetTimeofDay?????? */
    timeval_add(&currentTime, &__timer->interval, &__timer->timeout);

    /* ???NULL */
    __timer->list.next = __timer->list.prev = NULL;
    __timer->callback = callback;
    __timer->arg = arg;

    
    pthread_mutex_lock(&timer_list_lock);
    
    /* ???????????????????????? */
    timer_add_to_list(__timer);
    
    pthread_mutex_unlock(&timer_list_lock);

    return timerid;
}



/* ??????????????? */
int timer_del(unsigned long int timerid)
{
    struct timer_node *__this_timer = NULL;

    pthread_mutex_lock(&timer_list_lock);
    __this_timer = get_timer_byid(timerid);

    if((!__this_timer)) {
        warning("null pointer error.\n");
        pthread_mutex_unlock(&timer_list_lock);
        return -1;
    }

    /* ????????????????????????????????? */
    list_del_init(&__this_timer->list);
    pthread_mutex_unlock(&timer_list_lock);
    
    free(__this_timer);

    return 0;
}
//



void timer_initial()
{
    pthread_create(&timer_routine, NULL, sched_timer_list, NULL);

    pthread_setname_np(timer_routine, "timer");
}




void test_timer() 
{
    static unsigned long int timerid[10];
    
    void timer_callback(void*arg) {
        static volatile int count = 0;
        count++;
        unsigned long int *timerid = (unsigned long int *)arg;
        error("timerid = %ld, count = %d\n", *timerid, count);
    }
    
    int i=0;
    for(i=0;i<10;i++)
        timerid[i] = timer_new(true, timer_callback, &timerid[i], 1, 1);

    
    for(i=0;i<10;i++) {
        sleep(1);
        timer_del(timerid[9-i]);
    }
    error("----------------------------------\n");
    for(i=0;i<10;i++) {
        sleep(1);
        timerid[i] = timer_new(true, timer_callback, &timerid[i], 1, 1);
    }
}

