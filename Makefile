CC				= gcc
CFLAGS			= -Wall -pthread
S_F				= server.o trans.o
SERVER			= server
C_F				= client.o trans.o
CLIENT          = client

all:			$(SERVER) $(CLIENT)
$(SERVER):		$(S_F)
				$(CC) $(CFLAGS) -o $(SERVER) $(S_F)
				

$(CLIENT):		$(C_F)
				$(CC) $(CFLAGS) -o $(CLIENT) $(C_F)
				
clean:
				@rm -f $(C_F) $(SERVER) $(CLIENT) $(S_F)