EXE=a.out


all: test.o s.lds 
	gcc test.o -Wl,-Ts.lds

test.o: test.c
	gcc -c test.c -O0

gen_lds:
	ld --verbose >ld.lds

readelf:test.o a.out
	readelf -S test.o
