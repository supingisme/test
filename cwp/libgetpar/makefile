
define delete
@if [ -f $(LIB_BIN) ];then rm $(LIB_BIN);fi;
@if [ -f test ];then rm test;fi;
endef

INCLUDE=include

SRC=src/alloc.c  \
	src/atopkge.c \
	src/docpkge.c \
	src/ealloc.c \
	src/errpkge.c \
	src/getpars.c \
	src/strstuff.c \
	src/subcalls.c \
	src/tempname.c

LIB_BIN=lib/libgetpar.so


all:$(LIB_BIN)


$(LIB_BIN):
	gcc -shared -fPIC -I $(INCLUDE)  $(SRC) -o $@ -g3 -O3 -Wall -w

test:
	@if [ ! -f $(LIB_BIN) ];then make;fi;
	gcc test1/test.c -o $@ $(LIB_BIN) 

install:
	cp $(LIB_BIN) /usr/lib64/

.PHONY:clean
clean:
#rm $(LIB_BIN) test
	$(delete)
