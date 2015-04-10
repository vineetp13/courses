#include"clone_context_switch_overhead.h"
#include<sys/types.h>

#define BUF_SIZE 20
#define STACK_SIZE 4096

int func1(void* args){
	return 0;}


void clone_context_switch(void){
	int fd[2];
	int nbytes;
	char string[] ="teststring\n";
	char buffer[20];
	void* child_stack = malloc(STACK_SIZE);
	
	pipe(fd); //Reading from fd[0] and writing to fd[1]

	pid_t pid; 
	pid = clone(&func1, child_stack+STACK_SIZE, CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FILES, NULL);

	if(pid==-1){
		exit(1);}

	#define CLONE_CONTEXT_SWITCH {	\
	 if(pid==0){			\
		close(fd[0]);		\
		write(fd[1],string,BUF_SIZE);\
	}\
	if(pid>0){			\
		close(fd[1]);		\
		read(fd[0],buffer,20);	\
	}}\

	//printf("string is %s",buffer );}}
	PM_COUNT(CLONE_CONTEXT_SWITCH, "Clone context switch cost, "O_STR, 1000000);
	//exit(1);
	return ;}

void clone_context_switch_overhead(void){
	clone_context_switch();	
}
