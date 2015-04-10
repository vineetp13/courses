#include "measure.h"
#include "process_context_switch_overhead.h"

int main(int argc, char** argv) {
    set_top_priority();
    attach_to_cpu_0();

    printf("Quant, Mean, Median, First Run, Min, Max\n");
    process_context_switch_overhead();

    return 0;
}


