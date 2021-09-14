# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:04 CST. 
# -*- coding: utf-8 -*-

# 属性装饰器
class Student(object):
    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value,int):
            raise ValueError('必须输入数字！')
        if value<0 or value>100:
            raise ValueError('必须大于0小于100！')
        self._score = value

s = Student()
s.score = 12
s.score = 121
print(s.score)
