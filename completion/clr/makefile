

all:clr
clr:
	gcc clr.c -o clr

install:clr
	cp clr /usr/bin/
	cp clr-completion.bash /etc/bash_completion.d/
#source /etc/bash_completion.d/clr-completion.bash
uninstall:/usr/bin/clr
	rm -f /usr/bin/clr
	rm -f /etc/bash_completion.d/clr-completion.bash

clean:
	rm -f clr
	
