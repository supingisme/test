#!/bin/bash 

bpftrace -lv t:kvm:kvm_vcpu_wakeup


bpftrace -e 'tracepoint:kvm:kvm_vcpu_wakeup { 
	printf("kvm:kvm_vcpu_wakeup: %16ld\n", args->ns); 
	@[kstack, ustack, comm, pid] = count();
}'
