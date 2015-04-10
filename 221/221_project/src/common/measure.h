#ifndef __MEASURE_H__
#define __MEASURE_H__

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>

#include "qselect.h"

#define cycles(X,OUT)                                  \
{                                                      \
    register uint64_t out __asm__("rax");              \
    __asm__ __volatile__(                              \
    "mfence       ;// Ensure sequential execution.\n\t"                        \
    "rdtsc        ;// Get time stamp counter value. Stored in edx | eax\n\t"   \
    "shl rdx, 32  ;// Shift high bits.\n\t"                                    \
    "or  rax, rdx ;// Logical OR into output register.\n\t"                    \
    "mov r15, rax\n\t"                                                         \
    );                                                                         \
    X;                                                                         \
    __asm__ __volatile__(                                                      \
    "mfence       ;// \n\t"                                                    \
    "rdtsc        ;// \n\t"                                                    \
    "shl rdx, 32  ;// \n\t"                                                    \
    "or  rax, rdx ;// \n\t"                                                    \
    "sub rax, r15 ;// Subtract to find elapsed time. \n\t"                     \
    );                                                                         \
    OUT = out;                                                                 \
}

#define measure(F,MEAN,MEDIAN,SEQ,MIN,MAX,COUNT) \
{                                        \
    uint64_t sum = 0;                    \
    uint64_t* seq = (uint64_t*)malloc(COUNT*sizeof(uint64_t)); \
    for (int i = 0; i < COUNT; ++i) {    \
        int tmp;                         \
        cycles(F, tmp);                  \
        seq[i] = tmp;                    \
        sum += tmp;                      \
    }                                    \
    MEAN = (double)sum/COUNT;            \
    MEDIAN = quick_select(seq, COUNT);   \
    SEQ = seq[0];                        \
    MIN = seq[0];                        \
    MAX = seq[0];                        \
    for (int i = 1; i < COUNT; ++i) {    \
        if (MIN > seq[i]) MIN = seq[i];  \
        if (MAX < seq[i]) MAX = seq[i];  \
    }                                    \
    free(seq);                           \
}

// These are for easy 
#define PM_COUNT(F,STR,COUNT) { double __m; uint64_t __med,  __seq, __min, __max; measure(F,__m,__med,__seq,__min,__max,COUNT); printf(STR,__m,__med,__seq,__min,__max); }
#define PM(F,STR) { PM_COUNT(F,STR,10000); }
#define O_STR "%lf, %ld, %ld, %ld, %ld\n"
#define PM_(F,STR) { PM_COUNT(F,STR,1); }


void set_top_priority();
void attach_to_cpu_0();

#endif
