SOURCES:= $(wildcard *.c) $(wildcard *.h)
OBJECTS:= $(wildcard *.c)
MYSQL:= $(mysql_config --cflags --libs)
OUT:= main

main: $(SOURCES)
	cc -W -Wall -o $(OUT) $(OBJECTS) `mysql_config --cflags --libs`

