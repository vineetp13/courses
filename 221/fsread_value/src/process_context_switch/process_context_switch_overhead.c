#include"process_context_switch_overhead.h"
#include<sys/types.h>

#define BUF_SIZE 20

void process_context_switch(void){
	int fd[2];
	int nbytes;
	char string[] ="teststring\n";
	char buffer[20];

	pipe(fd); //Reading from fd[0] and writing to fd[1]

	pid_t pid = fork();
	if(pid==-1){
		exit(1);}

	#define CONTEXT_SWITCH {	\
	 if(pid==0){			\
		close(fd[0]);		\
		write(fd[1],string,BUF_SIZE);\
	}\
	if(pid>0){			\
		close(fd[1]);		\
		read(fd[0],buffer,20);	\
	}}\

	//printf("string is %s",buffer );}}
	PM_COUNT(CONTEXT_SWITCH, "Process context switch cost, "O_STR, 1000000);
	//exit(1);
	return ;}

void process_context_switch_overhead(void){
	process_context_switch();	
}
