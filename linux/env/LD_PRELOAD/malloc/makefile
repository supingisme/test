

all:
	@echo "make lib      :编译malloc动态库"
	@echo "make test     :编译示例程序"
	@echo "make ld       :设定LD_PRELOAD动态库"
	@echo "make reset    :取消使用LD_PRELAOD环境变量"
	@echo "               上面命令不起作用，请直接执行 # unset LD_PRELOAD"

lib:
	gcc -fpic -shared mymalloc.c -o libmymalloc.so 

test:
	gcc main.c

ld:
	@echo "请在终端输入：export LD_PRELOAD=$(PWD)/libmymalloc.so"

reset:
	unset LD_PRELOAD
