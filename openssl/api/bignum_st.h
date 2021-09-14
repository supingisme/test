/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
//crypto/bn.h 中定义了大数的表示方式，如下：
struct bignum_st
{
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
//各项意义如下：
//d：BN_ULONG(应系统而异，win32 下为4 个字节)数组指针首地址，大数就存放在这
        //里面，不过是倒放的。比如，用户要存放的大数为12345678000（通过BN_bin2bn 放入），
        //则d 的内容如下：0x30 0x30 0x30 0x38 0x37 0x36 0x35 0x34 0x33 0x32 0x31；
//top：用来指明大数占多少个BN_ULONG 空间，上例中top 为3。
//dmax：d 数组的大小。
//neg：是否为负数，如果为1，则是负数，为0，则为正数。
//flags：用于存放一些标记，比如flags 含有BN_FLG_STATIC_DATA 时，表明d 的内存
        //是静态分配的；含有BN_FLG_MALLOCED 时，d 的内存是动态分配的。
