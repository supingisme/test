CC=gcc
LDFLAGS= -l X11
CFLAGS= -g
PRGNAME=window
OBJ= main.o debug.o
DEPS= debug.h

all: application


application: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
		
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -rf *.o

distclean:
	rm -rf *.o $(PRGNAME)
