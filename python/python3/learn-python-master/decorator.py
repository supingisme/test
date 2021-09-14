# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
# coding=utf-8

# 定义一个装饰器
def mydecorator(func):
    def wrapper(*args,**kw):
        print('hi,now is:')
        print('args=', args)
        print('kwargs=', kw)
        return func(*args,**kw)
    return wrapper

# 使用装饰器
@mydecorator
def now(*args,**kw):
    print('2020.1.14')


now(123,12,3, a=1,b=2)

"""
D:\learn-python>python decorator.py
hi,now is:
args= (123, 12, 3)
kwargs= {'a': 1, 'b': 2}
2020.1.14


关于装饰器的具体概念，参见：
http://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000/001386819879946007bbf6ad052463ab18034f0254bf355000
"""
