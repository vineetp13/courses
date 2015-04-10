#include"pthread_context_switch_overhead.h"
#include <pthread.h>
#include<sys/types.h>

#define BUF_SIZE 20

void *HelloWorld1(void* args){
    void* ret = NULL;
    return ret;
;}

void pthread_context_switch(void){
	int fd[2];
	int nbytes;
	char string[] ="teststring\n";
	char buffer[20];
	pthread_t thread;

	pipe(fd); //Reading from fd[0] and writing to fd[1]

   	int err = pthread_create(&thread,NULL,HelloWorld1,NULL);
//	if(err!=0){
//		exit(1);}

	#define CONTEXT_SWITCH {	}\
/*	if(pid==0){			\
		close(fd[0]);		\
		write(fd[1],string,BUF_SIZE);\
	}\
	if(pid>0){			\
		close(fd[1]);		\
		read(fd[0],buffer,20);	\
	}}\
*/

	//printf("string is %s",buffer );}}
	PM_COUNT(CONTEXT_SWITCH, "Pthread context switch cost, "O_STR, 1000000);
	//exit(1);
	return ;}

void pthread_context_switch_overhead(void){
	pthread_context_switch();	
}
