/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
typedef struct
{
    char *section;
    char *name;
    char *value;
} CONF_VALUE;
//section 表明配置文件的段，
//name 表示这个段中的一个属性，value 则是这个属性的值。
//Openssl 采用哈希表来存放这些信息，便于快速查找。

