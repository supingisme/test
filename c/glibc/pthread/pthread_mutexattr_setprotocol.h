#include <pthread.h>

/* Mutex protocols.  */
enum
{
  PTHREAD_PRIO_NONE,

  //使用 PTHREAD_PRIO_INHERIT 可以避免优先级倒置。
  //低优先级的线程持有较高优先级线程所需的锁时，便会发生优先级倒置。
  //当线程由于拥有一个或多个具有 PTHREAD_PRIO_INHERIT 协议属性的健壮互斥而阻塞较高优先级的线程时，
  //它将以其优先级或最高优先级线程的优先级中较高的优先级执行，等待该线程拥有的任何健壮互斥并使用此协议进行初始化。//当一个线程由于拥有一个或多个具有PTHREAD_PRIO_INHERIT协议属性的非健壮互斥体而阻塞较高优先级的线程时，
  //它应以其优先级或最高优先级线程的优先级中的较高者执行，等待任何一个非健壮互斥体该线程拥有并使用此协议初始化。
  PTHREAD_PRIO_INHERIT, //继承,

  //当一个线程拥有一个或多个用 PTHREAD_PRIO_PROTECT 协议初始化的健壮互斥体时，
  //它应以该线程拥有并使用此属性初始化的所有健壮互斥体的优先级较高或最高优先级上限执行，
  //无论是否其他线程是否在这些健壮的互斥对象中被阻止。
  //
  //当线程拥有一个或多个使用PTHREAD_PRIO_PROTECT协议初始化的非健壮互斥体时，
  //它应以该线程拥有并使用此属性初始化的所有非健壮互斥体的优先级较高或最高优先级上限执行，
  //无论其他线程是否在这些非健壮互斥体上被阻塞，都不会受到影响。
  PTHREAD_PRIO_PROTECT

  //如果一个线程同时拥有用不同协议初始化的几个互斥锁，则它应以这些协议中的每个协议获得的最高优先级执行。
};


//get and set the protocol attribute of the mutex attributes object (REALTIME THREADS)
//获取并设置互斥量属性对象的协议属性（REALTIME THREADS）
int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *attr, int * protocol);
int pthread_mutexattr_setprotocol(pthread_mutexattr_t *attr, int protocol);

//pthread_mutexattr_getprotocol（）和
//pthread_mutexattr_setprotocol（）函数应分别获取并设置attr指向的互斥属性对象的协议属性，
//该对象先前由函数pthread_mutexattr_init（）创建。
//
//协议属性定义在使用互斥锁时要遵循的协议。协议的值可以是以下之一：
//
//PTHREAD_PRIO_INHERIT
//PTHREAD_PRIO_NONE
//PTHREAD_PRIO_PROTECT
//
//在<pthread.h>标头中定义。该属性的默认值应为PTHREAD_PRIO_NONE。
//当线程拥有具有PTHREAD_PRIO_NONE协议属性的互斥锁时，其优先级和调度将不受其互斥锁所有权的影响。
//
//当线程由于拥有一个或多个具有 PTHREAD_PRIO_INHERIT 协议属性的健壮互斥而阻塞较高优先级的线程时，
//它将以其优先级或最高优先级线程的优先级中较高的优先级执行，等待该线程拥有的任何健壮互斥并使用此协议进行初始化。
//
//当一个线程由于拥有一个或多个具有PTHREAD_PRIO_INHERIT协议属性的非健壮互斥体而阻塞较高优先级的线程时，
//它应以其优先级或最高优先级线程的优先级中的较高者执行，等待任何一个非健壮互斥体该线程拥有并使用此协议初始化。
//
//当一个线程拥有一个或多个用 PTHREAD_PRIO_PROTECT 协议初始化的健壮互斥体时，
//它应以该线程拥有并使用此属性初始化的所有健壮互斥体的优先级较高或最高优先级上限执行，
//无论是否其他线程是否在这些健壮的互斥对象中被阻止。
//
//当线程拥有一个或多个使用PTHREAD_PRIO_PROTECT协议初始化的非健壮互斥体时，
//它应以该线程拥有并使用此属性初始化的所有非健壮互斥体的优先级较高或最高优先级上限执行，
//无论其他线程是否在这些非健壮互斥体上被阻塞，都不会受到影响。
//
//当线程持有已使用PTHREAD_PRIO_INHERIT或PTHREAD_PRIO_PROTECT协议属性初始化的互斥锁时，
//如果更改了其原始优先级（例如通过更改），则该优先级不得移动到调度队列的尾部。
//调用sched_setparam（）。同样，当线程解锁已使用PTHREAD_PRIO_INHERIT或PTHREAD_PRIO_PROTECT协议属性初始化的互斥锁时，
//如果更改了其原始优先级，则该优先级将不被移动到调度队列的尾部。
//
//如果一个线程同时拥有用不同协议初始化的几个互斥锁，则它应以这些协议中的每个协议获得的最高优先级执行。
//
//当线程调用pthread_mutex_lock（）时，互斥锁使用值为 PTHREAD_PRIO_INHERIT 的协议属性进行初始化，
//当由于互斥锁由另一个线程拥有而导致调用线程被阻塞时，该所有者线程应继承调用的优先级线程，
//只要它继续拥有互斥体即可。实现应将其执行优先级更新为分配的优先级和所有继承的优先级中的最大值。
//此外，如果此所有者线程本身被另一个互斥体阻塞，且协议属性的值为PTHREAD_PRIO_INHERIT，
//则应以递归的方式将相同的优先级继承效果传播到该其他所有者线程。
//
//如果由pthread_mutexattr_getprotocol（）或pthread_mutexattr_setprotocol（）的attr参数指定的
//值未引用初始化的互斥锁属性对象，则该行为是不确定的。


//------------------------------------------------------------------------------------------------------------------------


//attr 指示以前调用 pthread_mutexattr_init() 时创建的互斥锁属性对象。
//protocol 可定义应用于互斥锁属性对象的协议。
//pthread.h 中定义的 protocol 可以是以下值之一：PTHREAD_PRIO_NONE、PTHREAD_PRIO_INHERIT 或 PTHREAD_PRIO_PROTECT。
//
//PTHREAD_PRIO_NONE 线程的优先级和调度不会受到互斥锁拥有权的影响。
//PTHREAD_PRIO_INHERIT 此协议值（如 thrd1）会影响线程的优先级和调度。
//
//如果更高优先级的线程因 thrd1 所拥有的一个或多个互斥锁而被阻塞，而这些互斥锁是用  PTHREAD_PRIO_INHERIT 初始化的，
//则 thrd1 将以高于它的优先级或者所有正在等待这些互斥锁（这些互斥锁是 thrd1 指所拥有的互斥锁）的线程的最高优先级运行。
//如果 thrd1 因另一个线程 (thrd3) 拥有的互斥锁而被阻塞，则相同的优先级继承效应会以递归方式传播给  thrd3。
//使用 PTHREAD_PRIO_INHERIT 可以避免优先级倒置。低优先级的线程持有较高优先级线程所需的锁时，便会发生优先级倒置。
//只有在较低优先级的线程释放该锁之后，较高优先级的线程才能继续使用该锁。设置 PTHREAD_PRIO_INHERIT，
//以便按与预期的优先级相反的优先级处理每个线程。如果为使用协议属性值 PTHREAD_PRIO_INHERIT 初始化的互斥锁定义了  
//_POSIX_THREAD_PRIO_INHERIT，则互斥锁的属主失败时会执行以下操作。
//属主失败时的行为取决于 pthread_mutexattr_setrobust_np() 的 robustness 参数的值。
//
//解除锁定互斥锁。互斥锁的下一个属主将获取该互斥锁，并返回错误 EOWNERDEAD。
//互斥锁的下一个属主会尝试使该互斥锁所保护的状态一致。如果上一个属主失败，则状态可能会不一致。
//如果属主成功使状态保持一致，则可针对该互斥锁调用  pthread_mutex_init() 并解除锁定该互斥锁。
//注 – 如果针对以前初始化的但尚未销毁的互斥锁调用 pthread_mutex_init()，则该互斥锁不会重新初始化。
//如果属主无法使状态保持一致，请勿调用 pthread_mutex_init()，而是解除锁定该互斥锁。
//在这种情况下，所有等待的线程都将被唤醒。以后对  pthread_mutex_lock() 的所有调用将无法获取互斥锁，
//并将返回错误代码 ENOTRECOVERABLE。现在，通过调用 pthread_mutex_destroy() 来取消初始化该互斥锁，
//即可使其状态保持一致。调用  pthread_mutex_init() 可重新初始化互斥锁。
//如果已获取该锁的线程失败并返回 EOWNERDEAD，则下一个属主将获取该锁及错误代码 EOWNERDEAD。
//PTHREAD_PRIO_PROTECT 当线程拥有一个或多个使用 PTHREAD_PRIO_PROTECT 初始化的互斥锁时，
//此协议值会影响其他线程（如  thrd2）的优先级和调度。
//thrd2 以其较高的优先级或者以 thrd2 拥有的所有互斥锁的最高优先级上限运行。
//基于被 thrd2 拥有的任一互斥锁阻塞的较高优先级线程对于 thrd2 的调度没有任何影响。 
//如果某个线程调用 sched_setparam()  来更改初始优先级，则调度程序不会采用新优先级将该线程移到调度队列末尾。
//
//线程拥有使用 PTHREAD_PRIO_INHERIT 或 PTHREAD_PRIO_PROTECT 初始化的互斥锁线程解除锁定
//使用 PTHREAD_PRIO_INHERIT 或 PTHREAD_PRIO_PROTECT  初始化的互斥锁 
//一个线程可以同时拥有多个混合使用 PTHREAD_PRIO_INHERIT 和 PTHREAD_PRIO_PROTECT 初始化的互斥锁。
//在这种情况下，该线程将以通过其中任一协议获取的最高优先级执行。

