# C flags:
#CFLAGS_OPTIMIZATION = -g
#CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-parameter
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)

# Libs to ALL modules:
LIBS = -lncurses

# System shell utilities
CC = gcc
RM = rm -f

all: clean
	$(CC) -o a a.c $(LIBS) $(CFLAGS)
	$(CC) -o b b.c $(LIBS) $(CFLAGS)
	$(CC) -o c c.c $(LIBS) $(CFLAGS) -Wno-unused-but-set-variable
	$(CC) -o d d.c ./wizardPattern/src/wizard_by_return.c $(LIBS) $(CFLAGS) -I./wizardPattern/inc/ -Wno-incompatible-pointer-types -Wno-unused-but-set-variable -Wno-int-conversion
	$(CC) -o e e.c $(LIBS) $(CFLAGS)

clean:
	-$(RM) a b c d e
