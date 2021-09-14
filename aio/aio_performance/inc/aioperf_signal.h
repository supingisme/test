#ifndef _AIOPERF_SIGNAL_H
#define _AIOPERF_SIGNAL_H

#include <signal.h>

void
aioperf_signal_setup();
void
aioperf_signal_action(int sig, siginfo_t *info, void *context);
void
aioperf_signal_block();
void
aioperf_signal_wait();

#endif