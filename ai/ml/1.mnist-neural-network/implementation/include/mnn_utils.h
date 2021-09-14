/**
 * 一些工具性的函数: 对应头文件mnn_utils.h
 *
 *    随机数、正态分布的随机数、sigmoid函数
 */
#ifndef MNN_UTILS_H
#define MNN_UTILS_H
//工具的头文件utils
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mnn_io.h"

/*断言：assert*/
void __assert (char* message, int condition);

/*强制退出：exit*/
void __exit (char* message);

/*转化整数：编码转化
int  00000000 00000000 00000000 00000000
char 00000000
*/
int reverse_int (int n);

/*随机double？ maybe， YES 2018.05.16*/
double drand (void);

/*正态分布double*/
double random_normal_distribution (void);

/*随机整数*/
int random_integer (int min, int max);

/*sigmoid函数*/
double sigmoid_to_number (double number);

/*sigmoid函数首要*/
double sigmoid_prime_to_number (double number);

#endif
