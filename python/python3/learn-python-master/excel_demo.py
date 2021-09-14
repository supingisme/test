# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 


import tablib #https://pypi.org/project/tablib/0.9.3/#files


headers = ('lie1', 'lie2', 'lie3', 'lie4', 'lie5')
mylist = [('23','23','34','23','34'),('sadf','23','sdf','23','fsad')]
mylist = tablib.Dataset(*mylist, headers=headers)
with open('excel.xlsx', 'wb') as f:
    f.write(mylist.xlsx)

'''
公司有个需求，需要把 json 文件，转成 excel 格式.

虽然，我刚学 python 不久，也深深的被 python 的简单易用和丰富的模块所吸引.

tablib 模块可以完美实现，json 转 excel

官方网址：https://pypi.python.org/pypi/tablib/0.9.3

系统环境：

    Centos 7.4

安装 tablib 模块
wget ttps://bootstrap.pypa.io/get-pip.py
python  get-pip.py
pip instal tablib

 测试代码如下:
#!/usr/bin/env python
# -*- coding: utf-8 -*-
 
import tablib
 
headers = ("name","age","weight")
data = [("buhaoxun","33","75kg"),("shaoxun","33","80kg"),("xun","33","85kg")]
data.append(("meili","33","90kg"))
 
data = tablib.Dataset(*data,headers=headers)
 
print data.json
 
open('xinxi.xls', 'wb').write(data.xls)

 导出 json 文件到 excel 代码 如下：
#!/usr/bin/env python
# -*- coding: utf-8 -*-
 
import tablib
 
data = tablib.Dataset()
 
f = open('xun.json', 'rb')
d = f.read()
f.close()
print d
data.json = d
open('bushaoxun.xls', 'wb').write(data.xls)

'''