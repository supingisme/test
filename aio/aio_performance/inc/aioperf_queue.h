#ifndef _aioperf_QUEUE_H
#define _aioperf_QUEUE_H

int
aioperf_queue_init(aioperf_queue_t *que);
int
aioperf_queue_release(aioperf_queue_t *que);
aioperf_io_task_t *
aioperf_queue_get(aioperf_queue_t *que);
void 
aioperf_queue_put(aioperf_queue_t *que, aioperf_io_task_t *io_task);

#endif
