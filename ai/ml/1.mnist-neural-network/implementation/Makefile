SRCDIR=src
INCLUDEDIR=include
CC=gcc
CFLAGS=-Wall

all:
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_utils.c $(CFLAGS) -o mnn_utils.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_io.c $(CFLAGS) -o mnn_io.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_data_structure.c $(CFLAGS) -o mnn_data_structure.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_file_utils.c $(CFLAGS) -o mnn_file_utils.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_parser_config_file.c $(CFLAGS) -o mnn_parser_config_file.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_network_utils.c $(CFLAGS) -o mnn_network_utils.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_network.c $(CFLAGS) -o mnn_network.o
		$(CC) -I${INCLUDEDIR} -c ${SRCDIR}/mnn_main.c $(CFLAGS) -o mnn_main.o
		$(CC) mnn_utils.o mnn_io.o mnn_data_structure.o mnn_file_utils.o mnn_network_utils.o mnn_parser_config_file.o mnn_network.o mnn_main.o $(CFLAGS) -o mnn_main -lm

clean:
		rm *.o
		rm mnn_main
