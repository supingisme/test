#!/bin/bash

gcc -O0 $*

perf stat ./a.out
