LINEHDRFLAG = 
XDRFLAG =  -DSUXDR
ENDIANFLAG = -DCWP_LITTLE_ENDIAN
LARGE_FILE_FLAG = -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE

CWP_FLAGS = $(LARGE_FILE_FLAG) $(ENDIANFLAG)  $(LINEHDRFLAG)

CC=gcc

ALL:bin/ximage bin/suximage

bin/ximage:
	$(CC) -o bin/ximage ./main/ximage.c \
            -D_drawcurve_v0 \
            ./lib/alloc.c \
            ./lib/atopkge.c \
            ./lib/axesbox.c \
            ./lib/colormap.c \
            ./lib/docpkge.c \
            ./lib/drawcurve.c \
            ./lib/ealloc.c \
            ./lib/errpkge.c \
            ./lib/exit.c \
            ./lib/fgettr.c \
            ./lib/filestat.c \
            ./lib/fputtr.c \
            ./lib/garnish.c \
            ./lib/getpars.c \
            ./lib/image.c \
            ./lib/intl2b.c \
            ./lib/legendbox.c \
            ./lib/rubberbox.c \
            ./lib/scaxis.c \
            ./lib/sort.c \
            ./lib/strstuff.c \
            ./lib/subcalls.c \
            ./lib/syscalls.c \
            ./lib/tempname.c \
            ./lib/window.c \
            -I./include -lm -lX11 -w $(CWP_FLAGS)
# bin/xwigb:
	# $(CC) -o bin/xwigb ./main/xwigb.c  \
            # -D_drawcurve_v1 -DCWPENDIAN=1 \
            # ./lib/alloc.c \
            # ./lib/atopkge.c \
            # ./lib/axesbox.c \
            # ./lib/colormap.c \
            # ./lib/docpkge.c \
            # ./lib/drawcurve.c \
            # ./lib/ealloc.c \
            # ./lib/errpkge.c \
            # ./lib/exit.c \
            # ./lib/fgettr.c \
            # ./lib/filestat.c \
            # ./lib/fputtr.c \
            # ./lib/garnish.c \
            # ./lib/getpars.c \
            # ./lib/image.c \
            # ./lib/intl2b.c \
            # ./lib/legendbox.c \
            # ./lib/rubberbox.c \
            # ./lib/rfwtva.c \
            # ./lib/rfwtvaint.c \
            # ./lib/scaxis.c \
            # ./lib/sort.c \
            # ./lib/strstuff.c \
            # ./lib/subcalls.c \
            # ./lib/syscalls.c \
            # ./lib/tempname.c \
            # ./lib/window.c \
            # -I./include -lm -lX11 -w $(CWP_FLAGS)

bin/suximage:
	$(CC) -o bin/suximage ./main/suximage.c \
            ./lib/alloc.c \
            ./lib/atopkge.c \
            ./lib/docpkge.c \
            ./lib/ealloc.c \
            ./lib/errpkge.c \
            ./lib/exit.c \
            ./lib/fgettr.c \
            ./lib/filestat.c \
            ./lib/fputtr.c \
            ./lib/getpars.c \
            ./lib/hdrpkge.c \
            ./lib/strstuff.c \
            ./lib/subcalls.c \
            ./lib/swapbyte.c \
            ./lib/syscalls.c \
            ./lib/tempname.c \
            ./lib/valpkge.c \
             -I./include -lm -lX11 -w -Wall $(CWP_FLAGS)
clean:
	rm -f ./bin/*
