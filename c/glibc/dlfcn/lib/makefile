all:libplug.so

libplug.so:lib.c
	gcc -o $@ $< -shared -fpic 

.PHONY:clean
clean:
	rm -rf libplug.so
