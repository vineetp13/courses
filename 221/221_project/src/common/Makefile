CC=gcc
CFLAGS=-masm=intel -std=c99 -O0 -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: clean $(OBJ)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -f $(EXE) *.o
