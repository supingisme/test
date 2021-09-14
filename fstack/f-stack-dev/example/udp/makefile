TOPDIR=..

ifeq ($(FF_PATH),)
	FF_PATH=${TOPDIR}
endif

ifeq ($(FF_DPDK),)
	FF_DPDK=${TOPDIR}/dpdk/x86_64-native-linuxapp-gcc
endif

LIBS+= -L${FF_PATH}/lib -Wl,--whole-archive,-lfstack,--no-whole-archive
LIBS+= -L${FF_DPDK}/lib -Wl,--whole-archive,-ldpdk,--no-whole-archive
LIBS+= -Wl,--no-whole-archive -lrt -lm -ldl -lcrypto -pthread -lnuma

all:
	@echo F-Stack FF_PATH=$(FF_PATH)
	@echo F-Stack FF_DPDK=$(FF_DPDK)
	@echo "Compile server-multithread-ring.c -> server-multithread-ring"
	@cc -O -gdwarf-2  -I../lib -o server-multithread-ring server-multithread-ring.c  \
				${LIBS} -Iasync_ring async_ring/async_ring.c
#	@echo "Compile server.c -> server"
#	@cc -O -gdwarf-2  -I../lib -o server server.c ${LIBS}	
#	@echo "Compile vos_ff_socket.c -> vos_ff_socket"
#	@cc -O -gdwarf-2  -I../lib -o vos vos_ff_socket.c vos_test.c vos_ff.c vos_ff_tools.c ${LIBS}
#	@echo "Compile client.c -> client"
#	@cc -O -gdwarf-2  -I../lib -o client client.c ${LIBS}

.PHONY: clean
clean:
	rm -f *.o server client

