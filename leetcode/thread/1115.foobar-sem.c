//1115. 交替打印FooBar
//我们提供一个类：
//
//class FooBar {
//  public void foo() {
//    for (int i = 0; i < n; i++) {
//      print("foo");
//    }
//  }
//
//  public void bar() {
//    for (int i = 0; i < n; i++) {
//      print("bar");
//    }
//  }
//}
//两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。
//
//请设计修改程序，以确保 "foobar" 被输出 n 次。
//
// 
//
//示例 1:
//
//输入: n = 1
//输出: "foobar"
//解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
//示例 2:
//
//输入: n = 2
//输出: "foobarfoobar"
//解释: "foobar" 将被输出两次。
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




/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
    int n;
    sem_t sem1;
    sem_t sem2;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&(obj->sem1), 0, 1);
    sem_init(&(obj->sem2), 0, 0);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&(obj->sem1));
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        sem_post(&(obj->sem2));
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&(obj->sem2));
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        sem_post(&(obj->sem1));
    }
}

void fooBarFree(FooBar* obj) {
    sem_destroy(&(obj->sem1));
    sem_destroy(&(obj->sem2));
    free(obj);
}




/////////////////////////////////////////////////////////////////////////////////////////////

void *thread_foo(void *arg) {
    FooBar* fb = (FooBar* )arg;
    foo(fb);
}

void *thread_bar(void *arg) {
    FooBar* fb = (FooBar* )arg;
    bar(fb);
}


int main(int argc, char *argv[]) {
    
    FooBar* foobar = fooBarCreate(atoi(argv[1]));
    
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_foo, foobar);
    pthread_create(&t2, NULL, thread_bar, foobar);

    

    sleep(1);
    fooBarFree(foobar);
}


