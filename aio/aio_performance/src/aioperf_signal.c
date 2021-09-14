#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <execinfo.h>
#include "aioperf_manager.h"
#include "aioperf_signal.h"


extern int process_state;
int release_all = 0;

void
aioperf_signal_setup()
{
    struct sigaction sigset;

    sigemptyset(&sigset.sa_mask);
    sigset.sa_flags = SA_SIGINFO;
    sigset.sa_sigaction = aioperf_signal_action;

    sigaction(SIGRTMIN + 1, &sigset, NULL);
    sigaction(SIGALRM, &sigset, NULL);
    sigaction(SIGINT, &sigset, NULL);
    sigaction(SIGIO, &sigset, NULL);
    sigaction(SIGCHLD, &sigset, NULL);
    sigaction(SIGPIPE, &sigset, NULL);
    sigaction(SIGSEGV, &sigset, NULL);
    sigaction(SIGHUP, &sigset, NULL);
    sigaction(SIGQUIT, &sigset, NULL);
    sigaction(SIGTERM, &sigset, NULL);
    sigaction(SIGKILL, &sigset, NULL);
}

void
aioperf_signal_action(int sig, siginfo_t *info, void *context)
{
    void            *fun_array[1024];
    char           **fun_name;
    size_t           sz = 0;
    unsigned int     j = 0;
    
    switch (sig) {
        case SIGALRM:
            process_state |= PROCESS_ALARM;
            return;
        case SIGQUIT:
            process_state |= PROCESS_QUIT;
            return;
        case SIGINT:
            process_state |= PROCESS_INT;
            return;
        case SIGTERM:
            process_state |= PROCESS_TERM;
            return;
        case SIGHUP:
            process_state |= PROCESS_HUP;
            return;
        case SIGCHLD:
            process_state |= PROCESS_CHLD;
            return;
        case SIGIO:
            process_state |= PROCESS_IO;
            return;
        case SIGPIPE:
            process_state |= PROCESS_PIPE;
            return;
            
        case SIGBUS:
            break;
        case SIGSEGV:
            break;
        case SIGABRT:
            break;

    }

    sz = backtrace(fun_array, 1024);
    fun_name = backtrace_symbols(fun_array, sz);
    for (j = 0; j < sz; j++) {
        printf("abort: %s\n", fun_name[j]);
    }

    free(fun_name);

    abort();
}

void
aioperf_signal_block()
{
    sigset_t     set;

    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigaddset(&set, SIGALRM);
    sigaddset(&set, SIGIO);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGHUP);
    sigaddset(&set, SIGTERM);
    sigaddset(&set, SIGQUIT);

    sigprocmask(SIG_BLOCK, &set, NULL);
    
}

void
aioperf_signal_wait()
{
    sigset_t    set;

    sigemptyset(&set);

    sigsuspend(&set);
}

