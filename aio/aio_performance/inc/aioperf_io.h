#ifndef _AIOPERF_IO_H
#define _AIOPERF_IO_H

int
aioperf_io_read(aioperf_io_task_t *io_task);
int
aioperf_io_write(aioperf_io_task_t *io_task);
int
aioperf_io_handler(aioperf_repository_t *repository);

#endif
