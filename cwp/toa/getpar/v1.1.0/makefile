define delete
@if [ -f test ];then rm test;fi;
endef

INCLUDE=./

SRC=getpars.c 

all:test

test:
	gcc test.c -o $@ $(SRC) -w

.PHONY:clean
clean:
	$(delete)
