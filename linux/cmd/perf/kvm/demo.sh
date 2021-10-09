#!/bin/bash 

# https://rtoax.blog.csdn.net/article/details/120677586
perf kvm --host --guest record -a -o my.perf.data
perf kvm --host --guest report -i my.perf.data

