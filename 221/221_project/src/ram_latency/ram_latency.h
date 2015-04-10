#ifndef __RAM_LATENCY_H__
#define __RAM_LATENCY_H__

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <assert.h>

#include "measure.h"

void ram_latency();

#endif
