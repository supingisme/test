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

#define printFoo() fprintf(stderr, "foo")
#define printBar() fprintf(stderr, "bar")

//gcc 1115.foobar.c -std=c99 -pthread




/////////////////////////////////////////////////////////////////////////////////////////////

typedef struct {
    int n;
    bool flag;
    pthread_mutex_t mutex;  
    pthread_cond_t  cond; 
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    obj->flag = true;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond,NULL);

    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (false == obj->flag) {
            pthread_cond_wait(&obj->cond,&obj->mutex);
        }

        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        obj->flag = false;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void bar(FooBar* obj) {
    for (int i = 0; i < obj->n; i++) {
        
        pthread_mutex_lock(&obj->mutex);
        while (true == obj->flag) {
            pthread_cond_wait(&obj->cond,&obj->mutex);
        }

        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        obj->flag = true;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void fooBarFree(FooBar* obj) {
    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cond);

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

