#ifndef __PAGE_FAULT_SERVICE_OVERHEAD_H__
#define __PAGE_FAULT_SERVICE_OVERHEAD_H__

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <assert.h>

#include "measure.h"

void page_fault_service_overhead();

#endif
