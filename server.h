#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX_C 10

int PORT, master_socket, opt = true, addrlen;
struct sockaddr_in address;