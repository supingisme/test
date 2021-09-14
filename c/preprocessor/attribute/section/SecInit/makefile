SRC:=test-main.c
LD:=rongtao-ld.lds
INC:=-I./ -I.

all:test

test: ${LD}
	gcc ${SRC} -T ${LD} ${INC} -o test

clean:
	rm -rf test
