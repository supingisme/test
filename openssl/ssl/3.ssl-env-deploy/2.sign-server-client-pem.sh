# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:07:20 CST. 
#!/bin/bash

openssl ca -in req1.pem -out sslclientcert.pem 
openssl ca -in req2.pem -out sslservercert.pem
