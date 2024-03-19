#include<pthread.h>
#include<iostream>
#include<unistd.h> // sleep()
#include"ch9.hpp"

using std::cout;
using std::endl;

// 堆、全局变量、主线程主动传递参数给子线程

void* cbk(void* arg)
{
    cout << "I am coming!" << endl;
    cout << "子线程ID: " << pthread_self() << endl;   
    // veep* var_st = new veep;
    veep* var_st = (veep*)arg;
    var_st->age = 18;
    var_st->name = "xiaoHeioZi";
    var_st->weight = 130;
    pthread_exit(var_st);
    // return NULL;
}

// g++ ./othertest/demo_thread.cpp ./src/ch9.cpp -I ./include -lpthread -o threadapp 
// 需要指定动态库 -lpthread
void thread_1()
{
    // 线程ID获取函数， pthread_t 无符号长整型
    // pthread_t pthread_self(); 
    pthread_t demo1;
    veep t1;
    // 线程创建函数
    pthread_create(&demo1, NULL, cbk, &t1);
    cout << "主线程ID: " << pthread_self() << endl;
    // 退出当前线程，不影响其他线程
    // 线程退出函数 void pthread_exit(void *__retval)
    // pthread_exit(NULL);

    //  函数会阻塞调用线程，直到指定的线程终止
    // 线程回收,每次只能回收一个子线程
    // 创建一个指向void*类型的指针。然而，这个指针自身并没有被初始化指向一个具体的地址，这意味着它的值是未定义的，  void** ptr;不行
    // void** ptr;

    void* ptr;
    pthread_join(demo1, &ptr);
    cout << "name: " << t1.name.c_str() << endl;
    cout << "weight: " << t1.weight << endl;
    cout << "age: " << t1.age << endl;

    // veep* t = (veep*)ptr;
    // cout << "name: " << (t->name).c_str() << endl;
    // cout << "age: " << t->age << endl;
    // cout << "weight: " << t->weight << endl;

    // delete var_st;
    // 注意，这里 t 和 var_st 是一样的，但只能使用该作用域内的。
    // 不能使用 ptr ,否则会报 deleting ‘void*’ is undefined
    // delete t;
    // 主线程挂起，放弃系统资源
    // sleep(1); 

}

void* cbk1(void*)
{
    for(int i=0; i < 6; ++i)
    {
        i++;
    }
    cout << "I am coming again!" << endl;
    cout << "子线程ID: " << pthread_self() << endl;   
    return NULL;
}
void thread_out()
{
    // 线程分离
    pthread_t pth1;
    pthread_create(&pth1, NULL, cbk1, NULL);

    // 将子线程与主线程分离，给主线程减负。
    // 子线程退出的时候，其占用的内核资源由系统的其他进程接收并管理
    // 不想让主线程被 pthread_join(子线程,xx) 阻塞
    pthread_detach(pth1); //子线程与主线程分离 

    // 线程取消
    // 分两步走： 1. 调佣 pthread_cancel(要杀死的进程ID);
    //          2. 要杀死的线程进行一次系统调用（硬件资源）（此次调用完之后就被杀死了）。
    pthread_cancel(pth1);

    // 线程id比较
    // pthread_equal() // 方便上层应用

    pthread_exit(NULL);
}
 
// 线程同步  
// 线程同步不是让多个线程同时去做某一件事（不是并行），而是按照一定顺序去执行（线性执行）（保证数据的安全性）
const int MAX = 50;
int num = 0;
// 现象：重复数数，数据没来得及从寄存器写回内存 
// 解决： 线程同步
// 方法（有4种）： 互斥锁、读写锁、条件变量、信号量
// 共享资源 -> 临界资源
pthread_mutex_t mute;
// pthread_mutex_init(&mute, NULL);
// pthread_mutex_destroy();
// pthread_mutex_trylock();//尝试加锁
void* cbk_t1(void*)
{
    for (int i = 0; i < MAX; i++)
    {
        pthread_mutex_lock(&mute);// 上锁和开锁包含着临界区 里面包含着共享资源
        // 临界区越小越好，缩小临界区的粒度
        int cur = num;
        cur++;
        // usleep(2);//微秒
        num = cur;
        cout << "线程1: " << pthread_self() << "  当前值： " << cur << endl;
        pthread_mutex_unlock(&mute);
        cout << "线程1 lock_out" << endl;
    }
    return NULL;
}
void* cbk_t2(void*)
{
    for (int i = 0; i < MAX; i++)
    {
        pthread_mutex_lock(&mute);
        int cur = num;
        cur++;
        // usleep(3);
        num = cur;
        cout << "线程2: " << pthread_self() << "  当前值： " << cur << endl;
        pthread_mutex_unlock(&mute);
        cout << "线程2 trylock" << endl;
    }
    return NULL;
}
void together()
{
    pthread_t t1, t2;
    // 锁创建
    pthread_mutex_init(&mute, NULL);
    // 创建线程
    pthread_create(&t1, NULL, cbk_t1, NULL);
    pthread_create(&t2, NULL, cbk_t2, NULL);

    // 线程回收
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    // 锁销毁
    pthread_mutex_destroy(&mute);
}