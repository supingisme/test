#!/bin/bash

gcc hello.c -o hello
gcc -S hello.c
objdump -d hello > hello.asm

