LIBS+= ptsTalk/ptsTalk.c

INCLUDE+=-I ptsTalk

LIB+=-lm -pthread -lrt



ALL:
	gcc master.c -o master ${LIBS} ${LIB} ${INCLUDE}
	gcc slave.c -o slave ${LIBS} ${LIB}	${INCLUDE}
	gcc test.c -o test
clean:
	rm *~
