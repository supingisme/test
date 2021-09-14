#ifneq ($(KERNELRELEASE),)
MODULE_NAME = ptsTalkKerMod
$(MODULE_NAME)-objs := ptsTalkMod.o
obj-m := $(MODULE_NAME).o
#else
#KERNEL_DIR=/lib/modules/`uname -r`/build
KERNEL_DIR=/lib/modules/3.10.0-693.el7.x86_64/build
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
	@mknod /dev/$(MODULE_NAME) c 231 0

rmmod:
	@echo "remove module"
	@rmmod $(MODULE_NAME)

rmnod:
	@echo "remove node"
	@rm /dev/$(MODULE_NAME)

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

