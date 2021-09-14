CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lrabbitmq
DEPS = utils.c utils.h

client.exe: $(DEPS)
	gcc $(CLFAGS) $(LDFLAGS) -o $@ main.c utils.c 

.PHONY: clean
clean: 
	rm -rf ./*.o ./*.exe
