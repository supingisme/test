all:plug.out

plug.out:dlopen.c
	@make -C ./lib/
	gcc $< -o $@  -ldl

.PHONY:clean 
clean:
	@make -C ./lib/ clean
	rm -rf  plug.out
