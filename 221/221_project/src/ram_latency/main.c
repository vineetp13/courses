#include "ram_latency.h"

int main(int argv, char** argc) 
{
    set_top_priority();
    attach_to_cpu_0();
	
	ram_latency();

    return 0;
}
