CC = gcc
AR = ar
DEBUG = -g
CFLAG =-Wall -Werror
LIB = -lpthread -leio -lrt -laio -lxio
TARGET = aioperf
ODIR = obj
SDIR = src
INC = -Iinc


_OBJS = aioperf_conf.o 		\
		aioperf_eventfd.o	\
		aioperf_file.o		\
		aioperf_manager.o	\
		aioperf_queue.o		\
		aioperf_signal.o	\
		aioperf_worker.o	\
		aioperf_memory.o	\
		aioperf_general.o	\
		aioperf_eio.o		\
		aioperf_aio.o		\
		aioperf_xio.o		\
		aioperf_libaio.o	\
		aioperf_io.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -fPIC -c $(INC) -o $@ $< $(CFLAGS) $(DEBUG)
	

.PHONY: all clean

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)  $(LIB)

clean:
	rm -rf $(ODIR)/*.o $(TARGET)
