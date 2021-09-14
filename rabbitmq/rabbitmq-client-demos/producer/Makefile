CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lrabbitmq
DEPS = main.c utils.c utils.h

producer.exe: $(DEPS)
	gcc $(CLFAGS) $(LDFLAGS) -o $@ main.c utils.c 

.PHONY: clean
clean:
	rm -rf ./*.o ./*.exe
	
