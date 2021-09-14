LIBRARY=`pkg-config --libs --cflags xmu` -lX11 -lm
LIBS=../lib/*.c
LIBS_XTCWP=lib/Xtcwp/*.c
MACRO=-DCWPENDIAN=1
INCLUDE=../include/

BIN=test1

all:$(BIN)

test1:
	gcc main/ximage.c -o $@  -I $(INCLUDE)  $(LIBRARY) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/image.c \
			./lib/intl2b.c \
			./lib/intsinc8.c \
			./lib/inttable8.c \
			./lib/legendbox.c \
			./lib/mksinc.c \
			./lib/rfwtva.c \
			./lib/rfwtvaint.c \
			./lib/rubberbox.c \
			./lib/scaxis.c \
			./lib/sinc.c \
			./lib/sort.c \
			./lib/stoep.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c

clean:
	rm $(BIN)


