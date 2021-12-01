#include <stdio.h>	//printf
#include <string.h>	//strlen
#include <sys/socket.h>	//socket
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#include"trans.h"
#define HOST_NAME_MAX		64
int sock, PORT, trans = 0;
struct sockaddr_in server;
FILE *f;
char message[HOST_NAME_MAX + 15] , server_reply[5], pid[10];
char hostname[HOST_NAME_MAX + 1];

void start();