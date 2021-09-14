#!/usr/bin/env python3
# -*- coding:utf-8 -*-
# github:https://github.com/tangthis
# mysql数据库操作
# ??????????????????????

import mysql.connector
conn = mysql.connector.connect(host='192.168.2.182',port=33066,user='root', password='123456', database='test')
cursor = conn.cursor()
cursor.execute('select * from user where id = %s', ['1'])
values = cursor.fetchall()
print(values)
#
#?????????????????????????????#
#[root@localhost python3_demo-master]# python3 mysql1.py 
#Traceback (most recent call last):
#  File "mysql1.py", line 7, in <module>
#    import mysql.connector
#ModuleNotFoundError: No module named 'mysql'
#[root@localhost python3_demo-master]# pip3 install mysql
#WARNING: Running pip install with root privileges is generally not a good idea. Try `pip3 install --user` instead.
#Requirement already satisfied: mysql in /usr/local/lib/python3.6/site-packages
#Requirement already satisfied: mysqlclient in /usr/local/lib64/python3.6/site-packages (from mysql)

