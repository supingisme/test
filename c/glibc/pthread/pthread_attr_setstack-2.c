#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sys/prctl.h>

#define DBG_PRINT(fmt, args...) {printf("%s %d ", __FUNCTION__, __LINE__);printf(fmt,##args);}

/**
 * [msSleep 用nanosleep实现的毫秒级线程休眠]
 * @param msTime [description]
 */
void msSleep(unsigned msTime)
{
    struct timespec reqTime;
    struct timespec remTime;
    int ret = 0;

    if(msTime == 0)
    {
        DBG_PRINT("invalid argument!\n");
        return;
    }
    else if(msTime>=1000)
    {
        reqTime.tv_sec = msTime/1000;
        reqTime.tv_nsec = (unsigned long)((msTime%1000)*1000000UL);
    }
    else
    {
        reqTime.tv_sec = 0;
        reqTime.tv_nsec = (unsigned long)(msTime*1000000UL);
    }

    do
    {
        /**
         * 由于nanosleep在休眠线程过程中，线程可能会被中断唤醒，并且唤醒后，剩余的休眠时间会保存在
         * remTime中，所以使用remTime中的时间继续休眠线程;
         */
        ret = nanosleep(&reqTime, &remTime);
        if(-1 == ret)
        {
            switch(errno)
            {
                case EINTR:
                    reqTime.tv_sec = remTime.tv_sec;
                    reqTime.tv_nsec = remTime.tv_nsec;
                    continue;
                default:
                    break;
            }

        }
        break;
    }while(1);
}

#define BUFFER_LEN 0x3000

void *testThead1(void* arg)
{
    //设定线程名为zoobiTask1
    prctl(PR_SET_NAME, "zoobiTask1");

    char buffer[BUFFER_LEN];
    while(1)
    {
        DBG_PRINT("Start\n");
        msSleep(300);
        DBG_PRINT("End\n");
    }
}

#define THREAD_STACK_LEN 0x4001
int main(int argc, const char* argv[])
{
    pthread_t thread1ID;
    pthread_attr_t attr;

    int ret = 0;
    void *stackAddr = NULL;
    //获取linux的页大小
    int paseSize = getpagesize();

    DBG_PRINT("The linux page size:0x%x\n", paseSize);

    pthread_attr_init(&attr);
    /**
     * 申请内存，并且内存以页大小对齐，需要申请的内存大小必须是2的整数次幂;
     * 经常用的malloc申请的内存只会默认使用8bytes或者16bytes对齐(依赖平台是32位还是64位);
     */
    ret = posix_memalign(&stackAddr, paseSize, THREAD_STACK_LEN);
    if(0 != ret)
    {
        DBG_PRINT("posix_memalign failed, errno:%s\n", strerror(ret));
        return -1;
    }
#if 1
    /**
     * 设定线程运行栈地址和大小，栈大小最小为16KB，并且栈地址以页面对齐;
     */
    ret = pthread_attr_setstack(&attr, stackAddr, THREAD_STACK_LEN);
    if(0 != ret)
    {
        DBG_PRINT("pthread_attr_setstack failed, errno:%s\n", strerror(ret));
        return -1;
    }
#endif
    void *getstackaddr = NULL;
    size_t getstackSize = 0;
    pthread_attr_getstack(&attr, &getstackaddr, &getstackSize);
    DBG_PRINT("pthread_attr_getstack>>getstackaddr:%p, getstackSize:0x%x\n", getstackaddr, getstackSize);

    ret = pthread_create(&thread1ID, &attr, testThead1, NULL);
    if(ret != 0)
    {
        DBG_PRINT("pthread_create failed! errno:%s\n", strerror(ret));
        return -1;
    }
    pthread_detach(thread1ID);

    while(1)
    {
        msSleep(10000);
    }

    return 0;
}

