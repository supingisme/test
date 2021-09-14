/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 16日 星期四 19:43:02 CST. */
#include <stdio.h>
#include <openssl/dso.h>
#include <openssl/bio.h>

BIO func1(BIO_METHOD *a)
{
	printf("BIO func1(BIO_METHOD *a);\n");
}

BIO func2(BIO_METHOD *a)
{
	printf("BIO func2(BIO_METHOD *a)\n");
}
