#!/bin/bash

# θΏη¨εζ
# perf record -g command
perf record -g ls

perf report --stdio
