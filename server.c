#include"server.h"

int main(int argc, char *argv[]){

    PORT = atoi(argv[1]);
    
    if(PORT < 5000 || PORT > 64000){
        printf("Wrong PORT..\n");
        return 0;
    }

    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
	{
		printf("socket failed\n");
		return 0;
	}

    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
		sizeof(opt)) < 0 )
	{
		printf("setsockopt");
	}
	
	//type of socket created
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
		
	//bind the socket to localhost port 8888
	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Listener on port %d \n", PORT);
		
	//try to specify maximum of 3 pending connections for the master socket
	if (listen(master_socket, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
    
    addrlen = sizeof(address);
	puts("Waiting for connections ...");

    start();
    return 0;
}

void start(){
    
}