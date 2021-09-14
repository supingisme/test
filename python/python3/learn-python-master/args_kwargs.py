# Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
# encoding:utf-8

# -*- Python3可变参数 -*-

import webbrowser #浏览器

def alias(*args, **kwargs):
    print('args=', args)
    print('kwargs=', kwargs)
    return

alias(3, 23, 3, 3,a='hello',b=3,c='C',rong="aradf")

"""
输出：
args= (3, 23, 3, 3)
kwargs= {'b': 3, 'c': 'C', 'a': 'hello'}

小结：
*args表示任何多个无名参数，它是一个tuple
**kwargs表示关键字参数，它是一个dict
"""

# 具体参考资料
webbrowser.open('http://10.170.6.66/jt_omc_rt/index.php', 1)
