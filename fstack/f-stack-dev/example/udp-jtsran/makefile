TOPDIR=..

ifeq ($(FF_PATH),)
	FF_PATH=${TOPDIR}
endif

ifeq ($(FF_DPDK),)
	FF_DPDK=${TOPDIR}/dpdk/x86_64-native-linuxapp-gcc
endif

INCLUDES+= -I../../app/micro_thread/

LIBS+= -L${FF_PATH}/lib -Wl,--whole-archive,-lfstack,--no-whole-archive
LIBS+= -L${FF_DPDK}/lib -Wl,--whole-archive,-ldpdk,--no-whole-archive
LIBS+= -Wl,--no-whole-archive -lrt -lm -ldl -lcrypto -pthread -lnuma

#LIBS+= ../../app/micro_thread/libmt.a


all:
	@echo F-Stack FF_PATH=$(FF_PATH)
	@echo F-Stack FF_DPDK=$(FF_DPDK)
	@echo "Compile cuup.c -> cuup"
	@cc -O -gdwarf-2  -I../lib -o cuup cuup.c vos_ff_socket.c vos_ff.c vos_ff_tools.c ${LIBS} ${INCLUDES}
	@echo "Compile du.c -> du"
	@cc -O -gdwarf-2  -I../lib -o du du.c vos_ff_socket.c vos_ff.c vos_ff_tools.c ${LIBS} ${INCLUDES}
	@echo "Compile cn.c -> cn"
	@cc -o cn cn.c

	

.PHONY: clean
clean:
	rm -f *.o cn cuup du

