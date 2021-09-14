#ifneq ($(KERNELRELEASE),)
MODULE_NAME = hellomodule
$(MODULE_NAME)-objs := hello.o
obj-m := $(MODULE_NAME).o
#else
KERNEL_DIR=/lib/modules/`uname -r`/build
MODULEDIR := $(shell pwd)

.PHONY:modules
default:modules

modules:
	make -C $(KERNEL_DIR) M=$(MODULEDIR) modules
	gcc test.c -o test.out

insmod:
	@echo "insert load module"
	@insmod $(MODULE_NAME).ko

mknod:
	@echo "make node "
	@mknod /dev/hello c 231 0

rmmod:
	@echo "remove module"
	@rmmod $(MODULE_NAME)

rmnod:
	@echo "remove node"
	@rm /dev/hello

clean distclean:
	@echo "clean"
	@rm -rf *.o *.mod.c .*.*.cmd *.ko *.out
	@rm -rf .tmp_versions *.symvers *.order
#endif

#MODULE_NAME=hellomodule

#insmod:
#	insmod $(MODULE_NAME).ko

#rmmod:
#	rmmod $(MODULE_NAME)

