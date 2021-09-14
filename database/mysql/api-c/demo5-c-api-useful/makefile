CC     = gcc
CFLAGS = -g -O2 -Wall -Wextra -pedantic -std=c99

SOURCES = $(wildcard *.c)

# Options needed for compiling or linking
MYSQL_I = `mysql_config --cflags`
MYSQL_L = `mysql_config --libs`
#
all:client

client: $(SOURCES)
	$(CC) $(CFLAGS) -o $@  $(SOURCES) $(MYSQL_I) $(MYSQL_L)
#
