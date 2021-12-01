#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include<stdlib.h>
#include<time.h>
#include"trans.h"
#include <sys/time.h>
#include<pthread.h>
#define MAX_C 30

int PORT, socket_desc , client_sock , c , read_size, i = 0;
struct sockaddr_in server , client;
char client_message[20], summary[2000] = "SUMMARY\n  ";
struct timeval end, strt;
time_t timer;
double t;
FILE *f;
pthread_t thread_id;
void start();
void *myThreadFun(void *vargp);