#ifndef _AIOPERF_AIO_H
#define _AIOPERF_AIO_H

#include <aio.h>

int
aioperf_aio_init(aioperf_manager_t *mgr);
void
aioperf_aio_release(aioperf_manager_t *mgr);
int
aioperf_aio_write(aioperf_io_task_t *io_task);
int
aioperf_aio_read(aioperf_io_task_t *io_task);
void
aioperf_aio_callback(sigval_t sig);
int
aioperf_aio_handler(aioperf_repository_t *repository);


#endif
