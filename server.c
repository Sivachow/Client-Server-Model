#include"server.h"

int main(int argc, char *argv[]){

    PORT = atoi(argv[1]);
    
    if(PORT < 5000 || PORT > 64000){
        printf("Wrong PORT..\n");
        return 0;
    }

    //Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( PORT );

    //Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return 1;
	}

	printf("Using port %d\n", PORT);
    while(1){
        i++;
        start();
    }
}

void start(){
	//Listen

	listen(socket_desc , 3);
    //Accept and incoming connection
	c = sizeof(struct sockaddr_in);
	
	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed");
		return;
	}

	int n, s = 3;
	//Receive a message from client
	while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
	{
		//Send the message back to client
        time(&now);
		n = client_message[1] - '0';
		if(client_message[2] != ' ')
		{
			n = n*10 + (client_message[2] - '0') + (s++)*0;
			if(client_message[3] != ' ')
				n = n*10 + (client_message[2] - '0') + (s++)*0;
		}
		printf("%ld:\t  #%-4d (%c %3d) from %s\n", now, i, client_message[0], n, client_message + s);
		Trans(n);
		write(client_sock , "Done" , 5);
	}
	
	if(read_size == 0)
	{
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("recv failed");
	}
}