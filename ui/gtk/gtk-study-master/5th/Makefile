## Created by Anjuta

 CC = gcc
 CFLAGS = -g -Wall

 INCFLAGS = 
 LDFLAGS = -Wl,-rpath,/usr/local/lib
 LIBS =$(shell pkg-config --cflags --libs gtk+-2.0 )

GTKFLAGS=-export-dynamic `pkg-config --cflags  `
all: test

test: $(OBJECTS)
	gcc -o test main.c common_func.c window_main.c window_test.c `pkg-config --cflags --libs gtk+-2.0`



 clean:
    rm -f *.o *.d

 .PHONY: all
 .PHONY: count
 .PHONY: clean
