obj-m += hrtimer_test.o
KERNELDIR=/lib/modules/`uname -r`/build
all:
	make -C  $(KERNELDIR) M=$(PWD) modules

clean: 
	make -C $(KERNELDIR)  M=$(PWD) clean
