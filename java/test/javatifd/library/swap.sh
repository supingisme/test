#!/bin/bash


javac swap.java

javah -jni swap

gcc -shared -fpic -o libswap.so -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux swap.c

#java -Djava.library.path=. Main
