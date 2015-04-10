#ifndef __SYSTEM_CALL_OVERHEAD_H__
#define __SYSTEM_CALL_OVERHEAD_H__

#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/syscall.h>

#include "measure.h"
//#include<asm/cachectl.h>

void system_call_overhead();

#endif
