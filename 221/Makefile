CC=gcc
CFLAGS=-O0 -pthread -std=c99 -O0 -mno-sse2 -masm=intel
SRC=$(wildcard:*.c)
OBJ=$(SRC:.c=.o)
EXE=kernel_threads

all=$(EXE)

$(EXE): $(EXE).c
	$(CC) $(CFLAGS) -o $(EXE) $(EXE).c

clean:
	rm $(EXE)
	rm $(EXE).o
