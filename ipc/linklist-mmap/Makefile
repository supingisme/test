# 编译 Makefile
# 荣涛 2021年8月2日

INC=-I.
LIB=mlinklist.c
GDB=-g -ggdb

all:
	gcc consumer.c ${LIB} ${INC} ${GDB} -o consumer
	gcc producer.c ${LIB} ${INC} ${GDB} -o producer

clean:
	rm -f consumer producer test.mmap
