#!/usr/bin/env python3
# -*- coding:utf-8 -*-
# github:https://github.com/tangthis
# 装饰器

def now():
	print('2015-1-1')

f = now
print(f())
print(f.__name__)
#2015-1-1
#None       ??????????????????????????
#now


#假设我们要增强now()函数的功能，比如，在函数调用前后自动打印日志，
#但又不希望修改now()函数的定义，这种在代码运行期间动态增加功能的方式，称之为“装饰器”（Decorator）


def log(func):
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper

@log
def now():
    print('2015-1-1')

print(now())
#call now():
#2015-1-1
#None



def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator

@log('execute')
def now():
    print('2015-1-1')

print(now())
#execute now():
#2015-1-1
#None

#functools模块是为了高阶函数（该高阶函数的定义为作用于或返回其它函数的函数）而设置的。
#一般来说，任何可调用的对象在该模块中都可被当做函数而处理。
import functools#

def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper

print(log(now))
#<function log.<locals>.decorator.<locals>.wrapper at 0x7fbab9c677b8>    ???????????????????????????????

