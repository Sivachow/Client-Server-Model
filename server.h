#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include<stdlib.h>
#include<time.h>
#include"trans.h"

#define MAX_C 30

int PORT, socket_desc , client_sock , c , read_size;
time_t     now;
struct sockaddr_in server , client;
char client_message[2000];
int i = 0;
void start();