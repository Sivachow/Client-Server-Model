#include"client.h"

int main(int argc, char *argv[]){
    PORT = atoi(argv[1]);
	sprintf(pid, "%d", getpid());
    if(PORT < 5000 || PORT > 64000){
        printf("Wrong PORT..\n");
        return 0;
    }

    gethostname(hostname, HOST_NAME_MAX + 1);
	
	server.sin_addr.s_addr = inet_addr(argv[2]);
	server.sin_family = AF_INET;
	server.sin_port = htons( PORT );
    int i = 0;
    while(1){
		if(scanf("%s" , message) == EOF)
			break;
		if(message[0] == 'T')
        	start();
	}
    return 0;
}

void start(){
    sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
        return;
	}

    //Create socket
    printf("%s.%d", hostname, getpid());
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
		printf("\n%s --\n", message);
		//Send some data
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

		puts(server_reply);
	
	close(sock);
	return;
}