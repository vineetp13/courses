#include <pthread.h>
#include "pthread_overhead.h"

void *HelloWorld(void* args){
    void* ret = NULL;
    return ret;
;}

void test(){
   ;}

void create_thread(){  
   pthread_t thread;
   int err = pthread_create(&thread,NULL,HelloWorld,NULL);
   if(err==0){
;}
   else{
;}}
// pthread_exit(NULL);}

void pthread_overhead(){
   printf("pthread_overhead, 0,0\n");
   PM_COUNT(create_thread(),"pthread cost, "O_STR, 10000);}

