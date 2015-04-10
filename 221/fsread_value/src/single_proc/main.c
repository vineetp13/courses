#include "measure.h"
#include "measurement_overhead.h"
#include "system_call_overhead.h"

int main(int argc, char** argv) {
    set_top_priority();
    attach_to_cpu_0();

    printf("Quant, Mean, Median, First Run, Min, Max\n");
    measurement_overhead();
    system_call_overhead();

    return 0;
}

