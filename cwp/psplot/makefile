SRC_=./lib/alloc.c \
    ./lib/atopkge.c \
    ./lib/axesbox.c \
    ./lib/basic.c \
    ./lib/colormap.c \
    ./lib/docpkge.c \
    ./lib/ealloc.c \
    ./lib/errpkge.c \
    ./lib/getpars.c \
    ./lib/intl2b.c \
    ./lib/intsinc8.c \
    ./lib/inttable8.c \
    ./lib/legendbox.c \
    ./lib/mksinc.c \
    ./lib/psAxesBox3.c \
    ./lib/psAxesBox.c \
    ./lib/psDrawCurve.c \
    ./lib/psLegendBox.c \
    ./lib/rfwtvaint.c \
    ./lib/rfwtva.c \
    ./lib/scaxis.c \
    ./lib/sinc.c \
    ./lib/sort.c \
    ./lib/stoep.c \
    ./lib/strstuff.c \
    ./lib/subcalls.c \
    ./lib/tempname.c

MACRO=-DCWPENDIAN=1
LIBRARY=`pkg-config --libs --cflags xmu` -lX11  -lm 
INCLUDE=include/

BIN=bin/psimage bin/psbbox bin/pscontour bin/pscube bin/pscubecontour \
    bin/psepsi bin/psgraph bin/pslabel bin/psmanager bin/psmerge \
    bin/psmovie bin/pswigb

define delete 
$(wordlist 1, $(words $(BIN)), $(BIN))
endef

all: $(BIN)

bin/psimage:
	gcc main/psimage.c -o $@ -I $(INCLUDE) $(LIBRARY) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/psbbox:
	gcc main/psbbox.c -o $@ -I $(INCLUDE) $(LIBRARY) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
            
bin/pscontour:
	gcc main/pscontour.c -o $@ -I $(INCLUDE) $(LIBRARY) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/psContour.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
            
bin/pscube:
	gcc main/pscube.c -o $@ -I $(INCLUDE) $(LIBRARY) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psCAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
            
bin/pscubecontour:
	gcc main/pscubecontour.c -o $@ -I $(INCLUDE) $(LIBRARY) \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psCAxesBox.c \
			./lib/psContour.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c

bin/psepsi:
	gcc main/psepsi.c -o $@ -I $(INCLUDE) $(LIBRARY) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/psgraph:
	gcc main/psgraph.c -o $@ -I $(INCLUDE) $(LIBRARY) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/pslabel:
	gcc main/pslabel.c -o $@ -I $(INCLUDE) $(LIBRARY) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/psmanager:
	gcc main/psmanager.c -o $@ -I $(INCLUDE) $(LIBRARY) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/psmerge:
	gcc main/psmerge.c -o $@ -I $(INCLUDE) $(LIBRARY) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/psmovie:
	gcc main/psmovie.c -o $@ -I $(INCLUDE) $(LIBRARY) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/legendbox.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/scaxis.c \
			./lib/sort.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
bin/pswigb:
	gcc main/pswigb.c -o $@ -I $(INCLUDE) $(LIBRARY) $(MACRO) -w \
			./lib/alloc.c \
			./lib/atopkge.c \
			./lib/axesbox.c \
			./lib/basic.c \
			./lib/colormap.c \
			./lib/docpkge.c \
			./lib/ealloc.c \
			./lib/errpkge.c \
			./lib/getpars.c \
			./lib/intl2b.c \
			./lib/intsinc8.c \
			./lib/inttable8.c \
			./lib/legendbox.c \
			./lib/mksinc.c \
			./lib/psAxesBox3.c \
			./lib/psAxesBox.c \
			./lib/psDrawCurve.c \
			./lib/psLegendBox.c \
			./lib/rfwtvaint.c \
			./lib/rfwtva.c \
			./lib/scaxis.c \
			./lib/sinc.c \
			./lib/sort.c \
			./lib/stoep.c \
			./lib/strstuff.c \
			./lib/subcalls.c \
			./lib/tempname.c
            
.PHONY:clean
clean:
	rm $(BIN)
#@echo $(delete)
#@for i in $(BIN); do if [ -f $i ];then rm $i; fi; done
