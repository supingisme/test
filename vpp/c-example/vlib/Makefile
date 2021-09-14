
CC=gcc

VPP_LIBS        := -lvlibmemoryclient
VPP_LIBS        += -lsvm
VPP_LIBS        += -lvppinfra 
VPP_LIBS        += -lvlib -lvlibmemory
VPP_LIBS        += -lvatplugin
 
LDFLAGS         += $(VPP_LIBS)
LDFLAGS         += -lpthread -lm -lrt -ldl -lcrypto

INCLUDES := -I/usr/include/vpp_plugins
CFLAGS   += $(INCLUDES)
 

all:
	gcc main_stub.c elog_samples.c -o test

        