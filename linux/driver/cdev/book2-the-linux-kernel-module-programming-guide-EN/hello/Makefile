obj-m += hello-1.o
obj-m += hello-2.o
obj-m += hello-3.o
obj-m += hello-4.o
obj-m += hello-5.o
obj−m += startstop.o
startstop−objs := start.o stop.o

KERNEL_DIR=/lib/modules/`uname -r`/build
MODULE_DIR := $(shell pwd)

all:
	make -C $(KERNEL_DIR) M=$(MODULE_DIR) modules
#	gcc nothing.c -o nothing.out
clean:
	make -C $(KERNEL_DIR) M=$(MODULE_DIR) clean

