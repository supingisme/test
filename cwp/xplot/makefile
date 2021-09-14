# ./lib/alloc.c \
# ./lib/atopkge.c \
# ./lib/axesbox.c \
# ./lib/colormap.c \
# ./lib/docpkge.c \
# ./lib/drawcurve.c \
# ./lib/ealloc.c \
# ./lib/errpkge.c \
#./lib/garnish.c \
# ./lib/getpars.c \
# ./lib/image.c \
# ./lib/intl2b.c \
# ./lib/intsinc8.c \
# ./lib/inttable8.c \
# ./lib/legendbox.c \
# ./lib/mksinc.c \
# ./lib/rfwtva.c \
# ./lib/rfwtvaint.c \
# ./lib/rubberbox.c \
# ./lib/scaxis.c \
# ./lib/sinc.c \
# ./lib/sort.c \
# ./lib/stoep.c \
# ./lib/strstuff.c \
# ./lib/subcalls.c \
#./lib/subdir.mk \
# ./lib/tempname.c \
# ./lib/window.c \
# ./lib/windows.c \
# ./lib/xContour.c

LIBRARY=`pkg-config --libs --cflags xmu` -lX11 -lm
LIBS=lib/*.c
LIBS_XTCWP=lib/Xtcwp/*.c
MACRO=-DCWPENDIAN=1
INCLUDE=include/
BIN=bin/xwigb bin/ximage bin/xmovie bin/xcontour bin/xpicker  bin/lcmap \
    bin/lprop bin/xgraph bin/suxcontour bin/suxgraph bin/suximage \
    bin/suxmax bin/suxmovie bin/suxpicker bin/suxwigb

all:$(BIN)
	
bin/xwigb:
	gcc main/xwigb.c -o $@ -I $(INCLUDE) $(LIBRARY) $(MACRO) \
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

bin/ximage:
	gcc main/ximage.c -o $@  -I $(INCLUDE)  $(LIBRARY) $(MACRO) \
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

bin/xmovie:
	gcc main/xmovie.c -o $@  -I $(INCLUDE) $(LIBS_XTCWP) $(LIBRARY) $(MACRO) \
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

bin/xcontour:
	gcc main/xcontour.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
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

bin/xpicker:
	gcc main/xpicker.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/garnish.c \
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

bin/xepsp:
	gcc main/xepsp.c -o $@  -I $(INCLUDE)   $(LIBS) $(LIBRARY) $(MACRO)

bin/lcmap:
	gcc main/lcmap.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
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
bin/lprop:
	gcc main/lprop.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
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
bin/xgraph:
	gcc main/xgraph.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
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
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suxcontour:
	gcc main/suxcontour.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suxgraph:
	gcc main/suxgraph.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suximage:
	gcc main/suximage.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suxmax:
	gcc main/suxmax.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/fputtr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suxmovie:
	gcc main/suxmovie.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suxpicker:
	gcc main/suxpicker.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
bin/suxwigb:
	gcc main/suxwigb.c -o $@  -I $(INCLUDE) $(LIBRARY) $(MACRO) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/drawcurve.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/fgettr.c \
			./lib/filestat.c \
			./lib/getpars.c \
			./lib/hdrpkge.c \
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
			./lib/swapbyte.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c \
			./lib/valpkge.c \
			./lib/window.c \
			./lib/windows.c \
			./lib/xContour.c \
			./lib/Xtcwp/Axes.c \
			./lib/Xtcwp/colormap.c \
			./lib/Xtcwp/fx.c \
			./lib/Xtcwp/misc.c \
			./lib/Xtcwp/resconv.c \
			./lib/Xtcwp/rubberbox.c 
clean:
	rm $(BIN)


