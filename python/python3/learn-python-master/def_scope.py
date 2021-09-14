# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
def bar(self, y):
    return self.x + y


class Foo(object):
    #定义类的时候，若是添加__init__方法，那么在创建类的实例的时候，实例会自动调用这个方法，一般用来对实例的属性进行初使化。
    def __init__(self, x):
        self.x = x

    Foo_bar = bar;
    

foo = Foo(333);
print(foo.Foo_bar(3))


#result:336

