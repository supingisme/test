#!/bin/bash

# 查看 当前系统中按个 CPU 占用 CPU 比例较大
sudo perf top --call-graph graph -U

# 只查看某个进程的情况
sudo perf top --call-graph graph -p 1 -K
