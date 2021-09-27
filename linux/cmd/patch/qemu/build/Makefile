
all: qemu-img

include config-host.mak

qemu-img: qemu-img.o qdev-monitor.o qdev-test.o
	@echo -e "\033[1;32m >>>>> CC=$(CC) <<<<< \033[m"
	$(CC) qemu-img.o qdev-monitor.o qdev-test.o -o $@

qdev-monitor.o: ../softmmu/qdev-monitor.c 
	@echo -e "\033[1;32m >>>>> CC=$(CC) <<<<< \033[m"
	$(CC) -c ../softmmu/qdev-monitor.c

qdev-test.o: ../softmmu/qdev-test.c 
	@echo -e "\033[1;32m >>>>> CC=$(CC) <<<<< \033[m"
	$(CC) -c ../softmmu/qdev-test.c 

qemu-img.o: ../qemu-img.c
	@echo -e "\033[1;32m >>>>> CC=$(CC) <<<<< \033[m"
	$(CC) ../qemu-img.c -c

install: qemu-img
	mkdir $$DESTDIR || :
	cp qemu-img $$DESTDIR

clean:
	rm -f qemu-img qemu-img.o qdev-monitor.o qdev-test.o
