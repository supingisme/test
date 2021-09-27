

all:io_uring-test link-cp
	
io_uring-test:
	gcc -Wall -O2 -D_GNU_SOURCE -o io_uring-test io_uring-test.c -luring

link-cp:
	gcc -Wall -O2 -D_GNU_SOURCE -o link-cp link-cp.c -luring

clean:
	rm -f io_uring-test link-cp
