

all:
	gcc -pg -c -o calculator.o calculator.c
	gcc -pg -c -o stack.o stack.c
	gcc -pg -c -o number.o number.c
	gcc -pg calculator.o stack.o number.o -o calculator

clean:
	rm -rf calculator ./*.o
