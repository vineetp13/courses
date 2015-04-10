#include "measure.h"
#include "file_contention.h"

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) 
{
    set_top_priority();
    attach_to_cpu_0();
	int num = atoi(argv[1]);
//	printf ("\n num is %d \n", num);

//    printf("Quant, Mean, Median, First Run, Min, Max\n");
//    	gen_files(num);
	file_contention(num);

    return 0;
}
