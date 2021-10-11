
obj-m += livepatch-sample-rtoax.o
obj-m += livepatch-callbacks-demo-rtoax.o
obj-m += loadavg_proc_show.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
