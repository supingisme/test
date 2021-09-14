#!/bin/bash

gcc  $*

perf stat ./a.out
