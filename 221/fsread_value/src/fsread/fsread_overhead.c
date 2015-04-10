#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "measure.h"

#define N_BLKS 256
#define BUF_SZ 4096
#define ITERATIONS 21

void gen_files()
{
	for (int i = 0; i < ITERATIONS; ++i)
	{
		int sz = 1<<i;
		char buf[256] = {0};
		sprintf(buf, "./generate_rand_file.sh %d.dat %d", sz, sz);
		if (0 != system(buf))
		{
			fprintf(stderr, "[Error] generating file %d.dat\n", sz);	
		}
	}
}

void fsread_overhead() 
{

	gen_files();

	for (int i = 0; i < ITERATIONS; ++i)
	{
		int sz = 1<<i;
		char buf[32] = {0};
		sprintf(buf, "./%d.dat", sz);
		// Open in direct and synchronous mode
		int fd = open(buf, O_DIRECT | O_RDONLY);
		fdatasync(fd);
		posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED);

		int blocks[N_BLKS] = {0};
		char input_buffer[BUF_SZ] = {0};

		for (int i = 0; i < N_BLKS; ++i)
		{
			blocks[i] = BUF_SZ*(rand() % sz);
		}
		
		// Measure

		// Random read
		#define RND_READ for (int i = 0; i < N_BLKS; ++i) 	\
		{													\
			lseek(fd, blocks[i], SEEK_SET);							\
			read(fd, input_buffer, BUF_SZ);					\
		}
		double m; uint64_t med, se, min, max;
		measure(RND_READ,m,med,se,min,max,1);
		//printf("Rnd_Read, "O_STR, m, med, se, min, max);
		printf("%d, ", BUF_SZ * sz);
		printf("Rnd_Read, "O_STR, m/N_BLKS, med/N_BLKS, se/N_BLKS, min/N_BLKS, max/N_BLKS);

		// Sequential read
		#define SEQ_READ for (int i = 0; i < N_BLKS; ++i) 	\
		{													\
			lseek(fd, i, SEEK_SET);							\
			read(fd, input_buffer, BUF_SZ);					\
		}
		measure(SEQ_READ,m,med,se,min,max,1);
		//printf("Seq_Read, "O_STR, m, med, se, min, max);
		printf("%d, ", BUF_SZ * sz);
		printf("Seq_Read, "O_STR, m/N_BLKS, med/N_BLKS, se/N_BLKS, min/N_BLKS, max/N_BLKS);
		
		close(fd);
	}
		
}
