
LD:=init/ld.lds

SRC:=./init/init.c\
	 main.c \
	 module1/module1_init.c \
	 module2/module2_init.c

INCLUDE:= -I./init \
		   -I./ \
		   -I./module1\
		   -I./module2


all:${SRC} ${LD} ${DEPS}
	gcc ${SRC} -Wl,-T${LD} ${INCLUDE}

clean:
	rm -f a.out
