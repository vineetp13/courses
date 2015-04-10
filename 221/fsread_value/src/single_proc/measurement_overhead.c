#include "measurement_overhead.h"

void p0() {
    ;
}

void p1(int a) {
    ;
}

void p2(int a, int b) {
    ;
}

void p3(int a, int b, int c) {
    ;
}

void p4(int a, int b, int c, int d) {
    ;
}

void p5(int a, int b, int c, int d, int e) {
    ;
}

void p6(int a, int b, int c, int d, int e, int f) {
    ;
}

void p7(int a, int b, int c, int d, int e, int f, int g) {
    ;
}

void measurement_overhead() {
    printf("Measurement, 0, 0\n");

    PM("","RDTSC, "O_STR);

    #define FOR_MEAS for (int k = 0; k < 100; ++k) { ; }
    double m; uint64_t med, se, min, max;
    measure(FOR_MEAS,m,med,se,min,max,10000);
    printf("Loop, "O_STR, m/100, med/100, se/100, min/100, max/100);

    printf("Function Calls, 0, 0\n");

    PM_COUNT(p0(), "p0, "O_STR,1000000);

    PM_COUNT(p1(1), "p1, "O_STR,1000000);

    PM_COUNT(p2(1,2), "p2, "O_STR,1000000);

    PM_COUNT(p3(1,2,3), "p3, "O_STR,1000000);

    PM_COUNT(p4(1,2,3,4), "p4, "O_STR,1000000);

    PM_COUNT(p5(1,2,3,4,5), "p5, "O_STR,1000000);

    PM_COUNT(p6(1,2,3,4,5,6), "p6, "O_STR,1000000);

    PM_COUNT(p7(1,2,3,4,5,6,7), "p7, "O_STR,1000000);
}

