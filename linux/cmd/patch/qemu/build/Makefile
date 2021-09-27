
all: qemu-img

qemu-img: qemu-img.o qdev-monitor.o
	$(CC) qemu-img.o qdev-monitor.o -o $@

qdev-monitor.o: ../softmmu/qdev-monitor.c 
	$(CC) -c ../softmmu/qdev-monitor.c

qemu-img.o: ../qemu-img.c
	$(CC) ../qemu-img.c -c

install: qemu-img
	mkdir $$DESTDIR || :
	cp qemu-img $$DESTDIR

clean:
	rm -f qemu-img qemu-img.o qdev-monitor.o
