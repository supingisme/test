
ALL:
	gcc -rdynamic -o main main.c dll.h -ldl  #-ldl (指定dl库)因为dlopen和dlsym在dl库中
	gcc -shared -o libmodule1.so module1.c dll.h -fpic
	gcc -shared -o libmodule2.so module2.c dll.h -fpic

clean:
	rm -f main libmodule1.so libmodule2.so 
