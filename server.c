#include"server.h"

int main(int argc, char *argv[]){
	f = fopen ("file.txt", "a+");
    PORT = atoi(argv[1]);
    if(PORT < 5000 || PORT > 64000){
        fprintf(f,"Wrong PORT..\n");
        return 0;
    }

    //Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
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
	timer = time(NULL) + 30;
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	fprintf(f, "Using port %d\n", PORT);
    while(1){
		timer = time(NULL) + 30;
		if(socket_desc == -1){
			pthread_detach(thread_id);
			return 0;
		}
        start();
    }
}

void *myThreadFun(void *vargp)
{
	while(1){
    	if(timer <= time(NULL)){
			close(socket_desc);
			socket_desc = -1;
			fprintf(f,"%s", summary);
			t = ((end.tv_sec*1000 +end.tv_usec/1000.0)/1000.0) - ((strt.tv_sec*1000 +strt.tv_usec/1000.0)/1000.0);
			fprintf(f,"  %.2f transactions/sec (%d/%.2f)\n",i/t, i,t );
			fclose(f);
			pthread_detach(thread_id);
			pthread_cancel(thread_id);
			exit(1);
		}
	}
	
}
void start(){
	//Listen)

	listen(socket_desc , 3);
    //Accept and incoming connection
	c = sizeof(struct sockaddr_in);
	
	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if(i == 0)
		 gettimeofday(&strt, NULL);
	if (client_sock < 0)
	{
		perror("accept failed");
		return;
	}

	int n, s = 3;
	
	//Receive a message from client
	if( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
	{
		//Send the message back to client
		if(client_message[0] != 'T'){
			strcat(summary, client_message);
			strcat(summary, "\n  ");
			return;
		}
		i++;
		n = client_message[1] - '0';
		if(client_message[2] != ' ')
		{
			n = n*10 + (client_message[2] - '0') + (s++)*0;
			if(client_message[3] != ' ')
				n = n*10 + (client_message[2] - '0') + (s++)*0;
		}

		gettimeofday(&end, NULL);
		fprintf(f,"%.2f:  #%-4d (%c%3d) from %s\n", (end.tv_sec*1000 +end.tv_usec/1000.0)/1000.0, i, client_message[0], n, client_message + s);
		Trans(n);
		gettimeofday(&end, NULL);
		write(client_sock , "Done" , 5);
		fprintf(f,"%.2f:  #%-4d (Done) from %s\n", (end.tv_sec*1000 +end.tv_usec/1000.0)/1000.0, i, client_message + s);		
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