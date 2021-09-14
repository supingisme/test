# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:04 CST. 
__author__ = 'tanteng'

import requests

def testrequests():

    url = 'http://10.173.1.51:9999/seeyon/main.do'

    params = {
        'x':'xxxx',
        'y':'yyyy'
    }

    re = requests.get(url,params)

    return re


if __name__ == '__main__':
    re = testrequests()
    print(re.text)

