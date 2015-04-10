#include "measure.h"
#include "file_cache_size.h"


int main(int argv, char** argc) 
{
    set_top_priority();
    attach_to_cpu_0();

    printf("Quant, Mean, Median, First Run, Min, Max\n");
    file_cache_size();

    return 0;
}
