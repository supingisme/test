# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:04 CST. 
# -*- coding: utf-8 -*-

# 使用requests保存远程图片(或文件)
import requests
import os


def saveRemoteImage():
    imgurl = 'http://10.173.1.51:9999/seeyon/fileUpload.do?method=showRTE&fileId=2092864872936457546&type=image'
    filename = imgurl.split('/')[-1] # sylincom的logo
    print(filename)
    path = './static/'+filename
    if not os.path.exists(path):
        r = requests.get(imgurl)
        with open(path, 'wb') as f:
            f.write(r.content)
            print('OK')
    else:
        print('Already exists.')

    """
    下载大文件这样写：
    for chunk in r.iter_content():
        f.write(chunk)

    如果不使用requests模块：
    import urllib
    urllib.urlretrieve(url, filename=None, reporthook=None, data=None)
    """

saveRemoteImage()
