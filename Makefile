CC				= gcc
CFLAGS			= -Wall -pthread -pedantic -g
S_F				= server.o trans.o
SERVER			= server
C_F				= client.o trans.o
CLIENT          = client

all:			$(SERVER) $(CLIENT) server.pdf client.pdf
$(SERVER):		$(S_F)
				$(CC) $(CFLAGS) -o $(SERVER) $(S_F)
				

$(CLIENT):		$(C_F)
				$(CC) $(CFLAGS) -o $(CLIENT) $(C_F)

server.pdf: 	server.man
				groff -man server.man -T pdf > server.pdf
client.pdf: 	client.man
				groff -man client.man -T pdf > client.pdf
				
clean:
				@rm -f $(C_F) $(SERVER) $(CLIENT) $(S_F) *.pdf

