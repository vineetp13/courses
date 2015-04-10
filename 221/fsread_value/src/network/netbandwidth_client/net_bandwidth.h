#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "../../common/measure.h"

#define BUF_SIZE 10485760

int netbandwidth_client();
//int netbandwidth_server();
