#!/bin/bash 

# 记录所有 kvm counter 
sudo perf stat -e 'kvm:*' -a sleep 10s

# Performance counter stats for 'system wide':
#
#             2,511      kvm:kvm_entry                                               
#                 0      kvm:kvm_hypercall                                           
#                 0      kvm:kvm_hv_hypercall                                        
#                 0      kvm:kvm_pio                                                 
#                 0      kvm:kvm_fast_mmio                                           
#                 0      kvm:kvm_cpuid                                               
#                25      kvm:kvm_apic                                                
#             2,511      kvm:kvm_exit
