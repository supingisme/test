# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
# -*- coding:utf-8 -*-
import tablib

table = open("dstTable.xls", "wb")#打开一个工作表
headers = ('first_name', 'last_name')
data = [
    ('John', 'Adams'),
    ('George', 'Washington')
]
data = tablib.Dataset(*data, headers=headers)
#添加新行
data.append(('Henry', 'Ford'))
#添加新列
data.append_col((90, 67, 83), header='age')
table.write(data.xls)#向表格写入数据
table.close()#关闭表格

