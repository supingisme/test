# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1

for i in fib(30):
	print(i)


def foo():
    print("starting...")
    while True:
        res = yield 4
        print("res:",res)
        
g = foo()
print(next(g))
print("*"*20)
print(next(g))	


def func():
    print("Start1")
    while True:
        res = yield 2
    print("End1")

a=func()
print("*"*20)
print(next(a))
print("*"*20)
print(next(a))
print("*"*20)
