all:
	gcc -o netbandwidth_client netbandwidth_client.c ../../common/measure.o ../../common/qselect.o -std=c99 -masm=intel -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread -I../common
