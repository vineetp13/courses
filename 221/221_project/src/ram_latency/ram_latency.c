#include"ram_latency.h"
#include<stdlib.h>
#include<stdio.h>
#include<inttypes.h> //to print uint64_t

#define ARRAYSIZE 1024 
#define CACHELINE 64
#define INTSIZE 4
#define NEXTLINE (CACHELINE/INTSIZE)
#define LINES_IN_ARRAY (ARRAYSIZE/NEXTLINE)
#define MAXSTRIDE 64
#define MAX_COUNT 10000
//int A[ARRAYSIZE];
//ARRAYSIZE is the number of elements in the array. 
// int is of size 4 Bytes. Since the cacheline is 64 Bytes, we access elements after 16. i.e. Access A[0], then access A[16] and so on 

/*
//First implementation where the array element in the next cacheline is accessed. This is not being used now. 
void measure_ram_latency(int *A, int size){	
	int i = 0;
	int temp = 0;
	while(i<size){
		temp = A[i];
		i = i+NEXTLINE;}
	
	return ;}
*/

// Working implementation where we chase the pointer 
void measure_ram_latency_chasing(void **p,int count){
	int loop_count = 0;

    register uint64_t out __asm__("rax");              
    __asm__ __volatile__(                             
    "mfence       ;// Ensure sequential execution.\n\t"                        
    "rdtsc        ;// Get time stamp counter value. Stored in edx | eax\n\t"   
    "shl rdx, 32  ;// Shift high bits.\n\t"                                    
    "or  rax, rdx ;// Logical OR into output register.\n\t"                    
    "mov r15, rax\n\t"                                                        
    );                                                                        
	for (;loop_count<MAX_COUNT;loop_count++)
		p = *p;
    __asm__ __volatile__(                                                      
    "mfence       ;// \n\t"                                                    
    "rdtsc        ;// \n\t"                                                    
    "shl rdx, 32  ;// \n\t"                                                    
    "or  rax, rdx ;// \n\t"                                                    
    "sub rax, r15 ;// Subtract to find elapsed time. \n\t"                     
    );                                                                         
    printf("%" PRIu64 "\n",out);
}
//	printf("%p\r",*p);

void ram_latency(){
	int **A;	
//	void **p;
	int stride,j,i=0;

//Start with stride size 1 and go uptill MAXSTRIDE
	for(stride=1;stride<=MAXSTRIDE;stride = stride*2){
		for(j=ARRAYSIZE;j<=ARRAYSIZE*ARRAYSIZE* 32 ;j = j * 2){
//Allocate an array of size j, where j will go from 1KB to 32MB
			A = malloc(j);

			for(i=0; i+1< (j)/(stride*sizeof(*A));i++){
				A[i*stride] = (int*) (A+(i+1)*stride);}
			A[i*stride] = (int*)A; // The last pointer points to the first one 
//			p = (void**)A;

			printf("%d - ", j);
			//PM_COUNT(measure_ram_latency_chasing((void **) A, j/stride),"Ram latency cost,"O_STR,100);
			measure_ram_latency_chasing((void **)A,j/stride);
			free(A);}}
	
	return ;}
