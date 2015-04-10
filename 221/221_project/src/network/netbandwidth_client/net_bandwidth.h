#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "../../common/measure.h"

//efine BUF_SIZE 52428800
#define BUF_SIZE 104857600
int netbandwidth_client();
//int netbandwidth_server();
