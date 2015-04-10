#include "measure.h"
#include "page_fault_service_overhead.h"


int main(int argv, char** argc) 
{
    set_top_priority();
    attach_to_cpu_0();

    page_fault_service_overhead();

    return 0;
}
