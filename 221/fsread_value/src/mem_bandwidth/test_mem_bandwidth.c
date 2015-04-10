#include "test_mem_bandwidth.h"
//#include "measure.h"
//#include "measure.c"
//#include "qselect.c"
//#include "qselect.h"
#include <stdlib.h>

#define UNROLL(stmt,N)		\
{				\
	for(int i=0;i<N;i+=1024){	\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
				\
				\
				\
				\
				\
				\
				\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;			\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;           	\
				\
	stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
        stmt;                   \
				\
				\
	}	\
}				\


int b,c;

void seq_write(double* arr, int n)
{
	UNROLL(arr[i] = i,n);
}

void seq_read(double* arr, int n)
{
	UNROLL(b = arr[i],n);
}

void rand_read2(double* arr,int n)
{
        UNROLL( b = arr[i];c = arr[n-i],n/2);
}

void rand_write2(double* arr,int n)
{
	UNROLL(arr[i] =  i;arr[n-i] = i,n/2);
}

int main()
{
      set_top_priority();
      attach_to_cpu_0();

        volatile double* source = (double*)malloc(1*1024*1024*sizeof(double));
        volatile double* dest = (double*)malloc(1*1024*1024*sizeof(double));
	volatile double* arr = (double*)malloc(1*1024*1024*sizeof(double));
	printf("%d\n",sizeof(double));
//      memcpy(dest,source,sizeof(source));
        PM_COUNT(memcpy(dest,source,1*1024*1024*sizeof(double)), "Memory Bandwidth, "O_STR,1000);
	
	PM_COUNT(seq_write(arr, 1048576), "Sequential Write, "O_STR,1000);
	
	PM_COUNT(rand_write2(arr, 1048576), "Random Write, "O_STR,1000);
	
	PM_COUNT(seq_read(arr, 1048576), "Sequential Read, "O_STR,1000);
	
	PM_COUNT(rand_read2(arr, 1048576), "Random Read, "O_STR,1000);

}
