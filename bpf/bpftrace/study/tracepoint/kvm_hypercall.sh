#!/bin/bash 

bpftrace -lv t:kvm:kvm_hypercall


bpftrace -e 'tracepoint:kvm:kvm_hypercall { printf("kvm:kvm_hypercall: %16d\n", args->nr); }'
