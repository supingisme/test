#ifndef _AIOPERF_LIBAIO_H
#define _AIOPERF_LIBAIO_H

#include <libaio.h>


#define AIOPERF_LIBAIO_QUEUE_SIZE  (60 * 1000)


int
aioperf_libaio_init(aioperf_manager_t *mgr);
void
aioperf_libaio_release(aioperf_manager_t *mgr);
int
aioperf_libaio_read(aioperf_io_task_t *io_task);
int
aioperf_libaio_write(aioperf_io_task_t *io_task);
void
aioperf_libaio_efd_handler(aioperf_repository_t *repository);
void
aioperf_libaio_efd2_handler(aioperf_repository_t *repository);

#endif
