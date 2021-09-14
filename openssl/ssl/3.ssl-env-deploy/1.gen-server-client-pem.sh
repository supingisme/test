# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:07:20 CST. 
#!/bin/bash
#rongtao

openssl req -newkey rsa:1024 -out req1.pem -keyout sslclientkey.pem 
openssl req -newkey rsa:1024 -out req2.pem -keyout sslserverkey.pem
