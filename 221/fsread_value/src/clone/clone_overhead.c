#include "measure.h"
#include "clone_overhead.h"

#define STACK_SIZE 4096

int func(void* args){
	return 0;}

void clone_(){
    pid_t pid;
	void* child_stack = malloc(STACK_SIZE);

	#define CLONE pid = clone(&func, child_stack+STACK_SIZE, CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FILES, NULL);\
    if (pid <= 0) return; 

    PM_COUNT(CLONE,"Clone cost,"O_STR,10);
}

void clone_overhead(){
	printf("clone_overhead, 0, 0\n");
	clone_();
}

