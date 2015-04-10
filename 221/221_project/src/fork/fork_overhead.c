#include"fork_overhead.h"

void test2(void){
	;}

void fork_(){
    pid_t pid;

    #define FRK pid = fork(); \
    if (pid <= 0) {           \
        return;               \
    }

    PM_COUNT(FRK,"Fork cost, "O_STR,10);
}

void fork_overhead(){
	printf("fork_overhead, 0, 0\n");
	//PM(test2(), "test2(), "O_STR);	
    fork_();
}
