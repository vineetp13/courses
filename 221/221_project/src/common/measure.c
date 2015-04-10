#include "measure.h"

void set_top_priority() {
    int which = PRIO_PROCESS;
    id_t pid;
    int priority = PRIO_MAX;
    int ret;

    pid = getpid();
    if (setpriority(which, pid, priority)) {
        printf("[ERROR] on setpriority, perhaps you are not root?\n");
    }
}

void attach_to_cpu_0() {
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0, &mask);

    if (sched_setaffinity(0, sizeof(mask), &mask)) {
        printf("[ERROR] on sched_setaffinity.\n");
    }
}
