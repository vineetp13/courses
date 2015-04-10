CC=gcc
CFLAGS=-masm=intel -std=c99 -O0 -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread -I../common
LDFLAGS=-L../common -lpthread
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXT_OBJ=$(wildcard ../common/*.o)
EXE=pthread_overhead

all: clean $(EXE) 

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) $(CLFAGS) -o $(EXE) $(OBJ) $(EXT_OBJ) $(LDFLAGS)

clean:
	rm -f $(EXE) *.o
