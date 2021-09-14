ifneq ($(KERNELRELEASE),)
          obj-m += interrupt.o
else
          KERNELDIR:=/12.3/kernel_android6.0.1_2.1.0_cqsound
          CROSS_COMPILE:=/12.3/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.9/bin/arm-linux-androideabi-
          PWD:=$(shell pwd)
  
default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) M=$(PWD) modules LOADADDR=0x10008000 KCFLAGS=-mno-android -Wall
  
  
clean:
	rm -rf *.o *.order .*.cmd *.ko *.mod.c *.symvers *.tmp_versions 
endif
