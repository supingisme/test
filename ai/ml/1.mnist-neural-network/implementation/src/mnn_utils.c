/**
 * 一些工具性的函数: 对应头文件mnn_utils.h
 *
 *    随机数、正态分布的随机数、sigmoid函数
 */
#include "mnn_utils.h"

/*与c语言的assert功能相同*/
void
__assert (char* message, int condition)
{
    if (!condition) {
        printf (ANSI_YELLOW "   [Assert fail]  " ANSI_RESET "%s.\n", message);

        exit (-2);
    }
}
/*与c语言exit功能相同*/
void
__exit (char* message)
{
    char buf[1024];

    strcpy (buf, message);
    strcat (buf, ".\n");

    print_error (buf);

    exit (-1);
}
/*转化整数
int  00000000 00000000 00000000 00000000
char 00000000
*/
int
reverse_int (int n)
{
    /* Thanks for the reverse_int function: */
    /* http://stackoverflow.com/questions/8286668/how-to-read-mnist-data-in-c/10409376#10409376 */
    unsigned char c1, c2, c3, c4;

    c1 = n & 255;
    c2 = (n >> 8) & 255;
    c3 = (n >> 16) & 255;
    c4 = (n >> 24) & 255;

    return ((int) c1 << 24) + ((int) c2 << 16) + ((int) c3 << 8) + c4;
}

/*返回一个伪随机数*/
double
drand (void)
{
    //RAND_MAX -> stdlib.h中 32767
    return (rand () + 1.0) / (RAND_MAX + 1.0);
}

/*返回一个 正态分布的随机数*/
double
random_normal_distribution (void)
{
    return sqrt (-2.0 * log (drand ())) * cos (2.0 * M_PI * drand ());
}

/*返回一个此范围内的伪随机数*/
int
random_integer (int min, int max)
{
    return min + rand () / (RAND_MAX / (max - min + 1) + 1);
}

/*sigmoid函数*/
double
sigmoid_to_number (double number)
{
/*
a    sigmoid = 0     i=-9999...99
b            = 0.5   i=0
c            = 1     i=9999...99
*/
    /* exp (double) returns a "double" value, so casting is not required */
    return 1.0 / (1.0 + exp (-number));
}

/*sigmoid的导数*/
double
sigmoid_prime_to_number (double number)
{
    /* Avoid to call same function 2 times */
    double sigmoid_number = sigmoid_to_number (number);

    return sigmoid_number * (1.0 - sigmoid_number);
}
