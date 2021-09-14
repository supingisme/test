#ifndef _AIOPERF_MANAGER_H
#define _AIOPERF_MANAGER_H

#include <pthread.h>
#include <sys/time.h>
#include <aio.h>
#include "aioperf_memory.h"

#if 0
char aioperf_data_512bytes[] = "<<testdata\
00000000001111111111222222222233333333334444444444\
55555555556666666666777777777788888888889999999999\
00000000001111111111222222222233333333334444444444\
55555555556666666666777777777788888888889999999999\
00000000001111111111222222222233333333334444444444\
55555555556666666666777777777788888888889999999999\
00000000001111111111222222222233333333334444444444\
55555555556666666666777777777788888888889999999999\
00000000001111111111222222222233333333334444444444\
55555555556666666666777777777788888888889999999999>>";
#endif

#define AIOPERF_OK                  0
#define AIOPERF_ERROR              -1
#define AIOPERF_READ                0
#define AIOPERF_WRITE               1
#define AIOPERF_TASKSIZE            4   //num of aioperf_data_512bytes
#define AIOPERF_FILE_SIZE           10  //num of AIOPERF_TASKSIZE
#define AIOPERF_FILE_READ_NUM       1
#define AIOPERF_FILE_WRITE_NUM      10000
#define AIOPERF_ULIMIT_MAX          (1000 * 1000)
#define AIOPERF_READ_FOLDER         "./test_data/test_read/"
#define AIOPERF_WRITE_FOLDER        "./test_data/test_write/"
#define AIOPERF_MBYTE_SIZE          (1024 * 1024)
#define AIOPERF_CONF_PATH           "./aioperf.conf"
#define AIOPERF_QUEUE_SIZE          (1000 * 1000)

enum {
    PROCESS_ALARM,
    PROCESS_QUIT,
    PROCESS_INT,
    PROCESS_TERM,
    PROCESS_HUP,
    PROCESS_CHLD,
    PROCESS_IO,
    PROCESS_PIPE
};

enum {
    USE_LIBAIO = 100,
    USE_LIBEIO,
    USE_XIO,
    USE_AIO,
    USE_IO
};

#if defined(_SC_PAGESIZE)
#define SYSPAGE_SIZE  sysconf(_SC_PAGESIZE)
#elif defined(_SC_PAGE_SIZE)
#define SYSPAGE_SIZE sysconf(_SC_PAGE_SIZE)
#else
#define SYSPAGE_SIZE 4096
#endif

typedef void *(*aioperf_worker_func_t)(void *data);


typedef struct aioperf_manager_s        aioperf_manager_t;
typedef struct ev_loop                  aioperf_loop_t;
typedef struct aioperf_worker_s         aioperf_worker_t;
typedef struct aioperf_io_task_s        aioperf_io_task_t;
typedef struct aioperf_queue_s          aioperf_queue_t;
typedef struct aioperf_conf_info_s      aioperf_conf_info_t;
typedef struct aioperf_conf_file_s      aioperf_conf_file_t;
typedef struct aioperf_repository_s     aioperf_repository_t;


struct aioperf_io_task_s {
    int                      fd;
    unsigned int             file_size;
    unsigned int             offset;
    aioperf_io_task_t       *file_next; //文件块指针，指向同一文件的下一个块
    aioperf_io_task_t       *task_next; //task指针，指向下一个task
    unsigned int             read_size;
    unsigned int             write_size;
    int                      notify_fd;
    aioperf_repository_t    *repository;
    int                      io_type;
    struct aiocb             aio_req;
    void                    *data;
    char                    *buf;
};

struct aioperf_queue_s {
    aioperf_io_task_t          *head;
    aioperf_io_task_t          *end;
    unsigned int                size;
    pthread_mutex_t             lock;
};

struct aioperf_conf_file_s {
    unsigned int             file_size;
    unsigned int             percent;
    aioperf_conf_file_t     *next;
};

struct aioperf_conf_info_s {
    unsigned int                file_num;
    aioperf_conf_file_t        *conf_file;
    unsigned int                buf_size;
};


struct aioperf_worker_s {
    pthread_t                   tid;
    int                         worker_release_start;
    int                         worker_release_done;
    aioperf_worker_t           *pre;
    aioperf_worker_t           *next;
    aioperf_manager_t          *mgr;
    int                         evfd;
    int                         epoll_fd;
    int                         loop_now;
    aioperf_pool_t             *pool;
};


struct aioperf_repository_s {
    aioperf_manager_t          *mgr;
    void                       *data;
    unsigned int                io_req_num;
    unsigned int                io_finish_num;
    unsigned int                io_error_num;
    aioperf_conf_info_t        *conf_info;
    char                       *buf;            //read or write buf
    struct timeval              t_start;
    struct timeval              t_end   ;
    struct timeval              t_elapse;
    aioperf_queue_t             que;
    aioperf_io_task_t         **files;
    aioperf_pool_t             *pool;
    int                         over_evfd;     //send eventfd when send finished 
    int                         signal_fd;
    int                         signal_fd2;

};

struct aioperf_manager_s {
    aioperf_worker_t            worker_head;
    pthread_mutex_t             worker_lock;
    void                       *data;
    aioperf_pool_t             *pool;
    aioperf_repository_t        read_repository;
    aioperf_repository_t        write_repository;
    int                         signal_fd;
    unsigned int                io_thread_num;
};



aioperf_manager_t *
aioperf_manager_create();
int
aioperf_manager_release(aioperf_manager_t *mgr);
int
aioperf_manager_repository_init(aioperf_manager_t *mgr);
void
aioperf_manager_repository_release(aioperf_manager_t *mgr);
int
aioperf_manager_get_aio_type(const char *type);


#endif
