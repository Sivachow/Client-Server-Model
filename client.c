#include"client.h"

struct timeval start_time, end;
double present;
int main(int argc, char *argv[]){
    PORT = atoi(argv[1]);
	sprintf(pid, "%d", getpid());

    if(PORT < 5000 || PORT > 64000){
        printf("Wrong PORT..\n");
        return 0;
    }

    gethostname(hostname, HOST_NAME_MAX + 1);
	char filename[40];
	strcpy(filename, hostname);
	strcat(filename, ".");
	strcat(filename, pid);
	f = fopen (filename, "a+");
	return 0;
	server.sin_addr.s_addr = inet_addr(argv[2]);
	server.sin_family = AF_INET;
	server.sin_port = htons( PORT );
    while(1){
		if(scanf("%s" , message) == EOF){
			sock = socket(AF_INET , SOCK_STREAM , 0);
			if (sock == -1)
			{
				printf("Could not create socket");
				return 0;
			}
			if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
			{
				perror("connect failed. Error");
				return 0;
			}
			sprintf(message, "%d", trans);
			strcat(message, " Transactions from ");
			strcat(message, hostname);
			strcat(message, ".");
			strcat(message, pid);
			if( send(sock , message , strlen(message)+1 , 0) < 0)
			{
				puts("Send failed");
				return 0;
			}
			printf("Sent %d Transactions\n", trans);
			break;
		}
		if(message[0] == 'T')
        	start();
		else{
			char num[4];
			num[0] = message[1];
			if(message[2] != ' '){
				num[1] = message[2];
				if(message[3] != ' '){
					num[2] = message[3];
					num[3] = '\0';
				}
				else
					num[2] = '\0';
			}
			else
				num[1] = '\0';
			printf("Sleep %d units \n", atoi(num));
			Sleep(atoi(num));
		}
		
	}
    return 0;
}

void start(){
	trans++;
    sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
        return;
	}

    //Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return;
	}
		strcat(message," ");
		strcat(message, hostname);
		strcat(message, ".");
		strcat(message, pid);
		char num[4];
		num[0] = message[1];
		if(message[2] != ' '){
			num[1] = message[2];
			if(message[3] != ' '){
				num[2] = message[3];
				num[3] = '\0';
			}
			else
				num[2] = '\0';
		}
		else
			num[1] = '\0';
		
		gettimeofday(&end, NULL);
		printf("%.2f:\t Send (%c %3s)\n", (end.tv_sec*1000 +end.tv_usec/1000.0)/1000.0, message[0], num);
		if( send(sock , message , strlen(message)+1 , 0) < 0)
		{
			puts("Send failed");
			return;
		}
		
		//Receive a reply from the server
		if( recv(sock , server_reply , 2000 , 0) < 0)
		{
			puts("recv failed");
			return;
		}
		gettimeofday(&end, NULL);
		printf("%.2f:\t Recv (%c %3s)\n", (end.tv_sec*1000 +end.tv_usec/1000.0)/1000.0, message[0], num);
		//Send some data
	
	close(sock);
	return;
}