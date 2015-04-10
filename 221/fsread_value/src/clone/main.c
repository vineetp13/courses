#include "measure.h"
#include "clone_overhead.h"

int main(int argc, char** argv) {
    set_top_priority();
    attach_to_cpu_0();

    printf("Quant, Mean, Median, First Run, Min, Max\n");
    clone_overhead();

    return 0;
}

