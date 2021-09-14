
OBJS=hdr.o main.o
DEPS=hdr.d main.d

all: $(OBJS)
	gcc -o jt_sran $(OBJS) 

%.o:%.c
	gcc -c $< -o $@ -O0 -g3 -Wall -rdynamic
	
%.d:%.c
	@echo "----------------";\
	set -e;rm -rf $@;
	@echo ">>> rm -rf $@"
	gcc -MM $< > $@.dep
	@echo "-------$@.dep--------"
	@cat $@.dep
	@sed 's,\($*\)\.o[ :]*,\1.o $@ :,g' < $@.dep > $@;\
	echo "--------$@----------";\
	cat $@; \
	rm -rf $@.dep
	

-include $(DEPS)
#main.o main.d : main.c hdr.h


clean:
	rm $(OBJS) $(DEPS) jt_sran


