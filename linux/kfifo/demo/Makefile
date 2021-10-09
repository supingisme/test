
obj-m += bytestream-example.o
obj-m += dma-example.o
obj-m += inttype-example.o
obj-m += record-example.c

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
