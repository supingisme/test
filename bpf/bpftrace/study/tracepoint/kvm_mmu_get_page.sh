#!/bin/bash 

bpftrace -lv t:kvmmmu:kvm_mmu_get_page


bpftrace -e 'tracepoint:kvmmmu:kvm_mmu_get_page { 
	printf("kvmmmu:kvm_mmu_get_page: %16ld\n", args->root_count); 
	@[kstack, ustack, comm, pid] = count();
}'
