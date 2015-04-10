#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "../../common/measure.h"

#define BUF_SIZE 200

int rtt_client();
int rtt_server();
