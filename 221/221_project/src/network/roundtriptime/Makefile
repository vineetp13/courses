all: 
	gcc -o rtt_client rtt_client.c ../../common/measure.o ../../common/qselect.o -std=c99 -masm=intel -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread -I../common
	gcc -o rtt_server rtt_server.c ../../common/measure.o ../../common/qselect.o -std=c99 -masm=intel -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread -I../common

testc:
	gcc -o rtt_client rtt_client.c ../../common/measure.o ../../common/qselect.o -std=c99 -masm=intel -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread -I../common

tests:
	gcc -o testserv testserv.c ../../common/measure.o ../../common/qselect.o -std=c99 -masm=intel -mno-sse2 -D_GNU_SOURCE -ffixed-r15 -g -pthread -I../common




