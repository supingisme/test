#ifndef _aioperf_EVENTFD_H
#define _aioperf_EVENTFD_H


int
aioperf_eventfd_create(int *evfd);
int
aioperf_eventfd_read(int evfd, unsigned long *val);
int
aioperf_eventfd_write(int evfd);
void
aioperf_eventfd_release(int evfd);
void
aioperf_eventfd_handler(aioperf_worker_t *worker);

#endif
