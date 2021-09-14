#!/bin/bash

gcc -shared -fpic -o lib/libRungeKutta.so -I$JAVA_HOME/include -I$JAVA_HOME/include/linux lib/RungeKutta.c
