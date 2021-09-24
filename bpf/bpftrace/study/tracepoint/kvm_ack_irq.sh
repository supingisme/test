#!/bin/bash 

bpftrace -lv t:kvm:kvm_ack_irq


bpftrace -e 'tracepoint:kvm:kvm_ack_irq { 
	printf("irqchip %4d, pin %16d\n", args->irqchip, args->pin); 
	@[kstack, ustack, comm, pid] = count();
}'
