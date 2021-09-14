#!/usr/bin/env python3
# -*- coding:utf-8 -*-
# github:https://github.com/tangthis

#dict
d={'Michale':95,'Tom':80,'Lee':99}
print(d)
print('Tom:',d['Tom'])

#key不存在情况
print('Tom' in d)
print('key not exist:',d.get('None'))
print('key not exist,print default val:',d.get('None',100))

#set
s = set([1,2,3])
print('set is:',s)
s.add(4)
print('set add element:',s)
s.remove(4)
print('set remove element:',s)

#{'Michale': 95, 'Tom': 80, 'Lee': 99}
#Tom: 80
#True
#key not exist: None
#key not exist,print default val: 100
#set is: {1, 2, 3}
#set add element: {1, 2, 3, 4}
#set remove element: {1, 2, 3}

