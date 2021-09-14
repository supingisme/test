CC=gcc
CFLAGS=`mysql_config --cflags --libs`

all: create_db get_dn analyze_dn

%:%.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY:clean
clean:
	rm create_db get_dn analyze_dn
