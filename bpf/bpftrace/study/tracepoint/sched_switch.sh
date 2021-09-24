#!/bin/bash

bpftrace -lv "tracepoint:sched:sched_switch"

bpftrace -e 'tracepoint:sched:sched_switch { 
	printf("%16s -> %16s\n", args->prev_comm, args->next_comm); 
	@[kstack, comm, pid] = count();
}'
