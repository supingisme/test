SRCS=connector.c fetch_data.c main.c
OBJS=$(patsubst %.c,%.o, $(SRCS))
target=main.out

CFLAGS=`mysql_config --libs --cflags`

all:$(OBJS)
	@echo "Compile >> $@"
	@gcc -o $(target) $(OBJS) $(CFLAGS)

$(OBJS):
	@echo "Compile >> $@"
	@gcc -o $@ -c $(patsubst %.o,%.c,$@) $(CFLAGS)

.PHONY:clean
clean:
	@rm -rf $(OBJS) $(target)
