# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
"""
演示Python如何动态创建变量
"""

pages = {}

for page in range(1, 50):
    """
    这里想创建变量page1 = 1, page2 = 2, page3 = 3,...
    """
    pages[page] = page

print(pages[1])

print(pages[2])
print(pages[47])


