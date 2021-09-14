块过滤器驱动
-------------------
这是Linux 3.x驱动程序的准系统过滤器驱动程序。这部分是受FGFT项目中的misc驱动程序启发的（在此github中）。
块过滤器是插入块请求的过滤器。默认情况下，该驱动程序插入/ dev / sda1。
您可以在misc.c中更改它或将其作为模块参数提供。

怎么运行的
-------------------
misc是Linux misc设备。它在内核中注册，并从给定的块设备字符串（例如/ dev / sda）中找到合适的块设备。
然后，它获取块设备队列，并用其自己的请求函数代替。虚拟请求功能只是回调原始功能。非常坦率的。

背景故事
-------------------
我想使用一个块过滤器驱动程序，并假设我可以在互联网上找到一个。但是，没有人找到，我写了自己的一部。
如果有人需要，我会将其放在我的github上。无担保。仅编译测试。

关键词
-------------------
Linux内核块过滤器驱动程序



Block filter driver
-------------------

This is a barebones filter driver for Linux 3.x driver. This is partially inspired from the misc driver in FGFT project (in this github). A block filter is one that interposes block request. By default this driver interposes /dev/sda1. You can change this in misc.c or provide it as a module parameter.



How it works
------------

misc is a Linux misc device. It registers with the kernel and finds the appropriate block device from the given block device string (like /dev/sda). It then obtains the block device queue and replaces the request function with its own. The dummy request function just calls back the original function. Fairly straightforward.


Backstory
---------

I wanted to use a block filter driver and assumed I would find one over the internet. However, there was none to be found and I wrote one of my own. I am putting this on my github if anyone needs it. NO WARRANTIES. COMPILE TESTED ONLY. 


Keywords
--------

Linux kernel block filter driver
