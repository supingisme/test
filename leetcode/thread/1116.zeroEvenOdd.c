//1116. 打印零与奇偶数
//假设有这么一个类：
//
//class ZeroEvenOdd {
//  public ZeroEvenOdd(int n) { ... }      // 构造函数
//  public void zero(printNumber) { ... }  // 仅打印出 0
//  public void even(printNumber) { ... }  // 仅打印出 偶数
//  public void odd(printNumber) { ... }   // 仅打印出 奇数
//}
//相同的一个 ZeroEvenOdd 类实例将会传递给三个不同的线程：
//
//线程 A 将调用 zero()，它只输出 0 。
//线程 B 将调用 even()，它只输出偶数。
//线程 C 将调用 odd()，它只输出奇数。
//每个线程都有一个 printNumber 方法来输出一个整数。请修改给出的代码以输出整数序列 010203040506... ，其中序列的长度必须为 2n。
//
// 
//
//示例 1：
//
//输入：n = 2
//输出："0102"
//说明：三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
//示例 2：
//
//输入：n = 5
//输出："0102030405"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

#define printFoo() fprintf(stderr, "foo")
#define printBar() fprintf(stderr, "bar")

//gcc 1115.foobar-sem.c -std=c99 -pthread
#define printNumber(i) fprintf(stderr, "%d", i)


typedef struct {
    int n;
//    int in;
    sem_t sem_zero;
    sem_t sem_even;
    sem_t sem_odd;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
//    obj->in = 0;
    sem_init(&(obj->sem_zero), 0, 1);
    sem_init(&(obj->sem_even), 0, 0);
    sem_init(&(obj->sem_odd), 0, 0);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    int i;
    for(i=0;i<obj->n;i++) {
        sem_wait(&(obj->sem_zero));

        printNumber(0);
        
        if(!(i%2))sem_post(&(obj->sem_even));
        if((i%2))sem_post(&(obj->sem_odd));
    }
}

void even(ZeroEvenOdd* obj) {
    int i;
    for(i=1;i<=obj->n;i+=2) {
        sem_wait(&(obj->sem_even));
        printNumber(i);
        sem_post(&(obj->sem_zero));
    }
    
}

void odd(ZeroEvenOdd* obj) {
    int i;
    for(i=2;i<=obj->n;i+=2) {
        sem_wait(&(obj->sem_odd));
        printNumber(i);
        sem_post(&(obj->sem_zero));
    }
    
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    
    sem_destroy(&(obj->sem_zero));
    sem_destroy(&(obj->sem_even));
    sem_destroy(&(obj->sem_odd));
    free(obj);
}

/////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////

void *thread_zero(void *arg) {
    ZeroEvenOdd* fb = (ZeroEvenOdd* )arg;
    zero(fb);
}

void *thread_even(void *arg) {
    ZeroEvenOdd* fb = (ZeroEvenOdd* )arg;
    even(fb);
}

void *thread_odd(void *arg) {
    ZeroEvenOdd* fb = (ZeroEvenOdd* )arg;
    odd(fb);
}


int main(int argc, char *argv[]) {
    
    ZeroEvenOdd* val = zeroEvenOddCreate(atoi(argv[1]));
    
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, thread_zero, val);
    pthread_create(&t2, NULL, thread_even, val);
    pthread_create(&t3, NULL, thread_odd, val);

    

    sleep(1);
    zeroEvenOddFree(val);
}



