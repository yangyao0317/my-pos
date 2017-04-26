#include <stdio.h>   
#include <sys/types.h>  
#include <unistd.h>   
#include <ctype.h>  
#include <pthread.h>   
#include <stdlib.h>  
#include <semaphore.h>  
  
#define MAX_THREAD 3 /* 线程的个数 */  
unsigned long long main_counter, counter[MAX_THREAD]; /* unsigned long  long是比long还长的整数 */  
//sem_t S1;  
void* thread_worker(void*);   
  
int main(int argc, char* argv[])  
{   
      int i, rtn, ch;   
      pthread_t pthread_id[MAX_THREAD] = {0}; /* 存放线程id*/      
       //sem_init(&S1,0,1);  
      for (i=0; i<MAX_THREAD; i++)    {   
         /* 在这里填写代码，用pthread_create建一个普通的线程，   
           线程id存入pthread_id[i]，线程执行函数是thread_worker  
           并i作为参数传递给线程 */  
           // if(pthread_create(&pthread_id[i], NULL, thread_worker, &i)!=0){  
      if(pthread_create(&pthread_id[i], NULL, thread_worker,&i)!=0){  
                      printf("thread_create failed");      
               exit(1);      
        }  
     }   
     do {/* 用户按一次回车执行下面的循环体一次。按q退出 */   
           unsigned long long sum = 0;/* 求所有线程的counter的和 */  
       for (i=0; i<MAX_THREAD; i++)  {/* 求所有counter的和 */  
              sum += counter[i];   
              printf("counter[%d]=%llu  ", i,counter[i]);   
         }  
        printf("%llu/%llu", main_counter, sum);     
     }  while ((ch = getchar()) != 'q');   
    //sem_destroy(&S1);  
   return  0;  
}   
void* thread_worker(void* p) {   
     int thread_num;    
    /* 在这里填写代码，把main中的i的值传递给thread_num */   
     //thread_num = *(int*)p;  
        thread_num = *(int*)(p);  
    for(;;) { /* 无限循环 */  
           counter[thread_num]++; /* 本线程的counter加一 */   
           //sem_wait(&S1);  
       main_counter++; /* 主counter 加一 */  
       //sem_post(&S1);  
     }   
}  