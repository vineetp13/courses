#include "net_bandwidth.h"

int rtt_server()
{
	int socket_desc,client_socket;
	struct sockaddr_in server,client;
	char recv_buf[BUF_SIZE];
	int read_size;
	if((socket_desc = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		printf("Socket Creation Error\n");
		return -1;
	}
	printf("Socket Created\n");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8080);

	if( bind(socket_desc, (const struct sockaddr *) &server, sizeof(server)) < 0 )
	{
		printf("Bind Error\n");
		return -1;
	}
	printf("Bind Success\n");

	if( listen(socket_desc, 3) < 0 )
	{
		printf("Listen Error\n");
		return -1;
	}
	
	printf("Waiting..\n");

	int sizeofstruct = sizeof(struct sockaddr_in);

/*	if( (client_socket = accept(socket_desc, (struct sockaddr* __restrict__) &client, (socklen_t* __restrict__) &sizeofstruct)) < 0 )
	{
		printf("Accept Failed. Return value: %d\n",client_socket);
		return -1;
	}
	printf("Client Connection Accepted\n");
*/
	while( (read_size = recvfrom(socket_desc, recv_buf, BUF_SIZE, 0,(struct sockaddr *) &client, &sizeofstruct)) > 0 )
	{
/*		*(recv_buf + read_size) = '\0';
		if( send(client_socket, recv_buf, strlen(recv_buf), 0) < 0 )
		{
			printf("Echo Reply Failed\n");
			return -1;
		}
*/
	}
	
	if(read_size == 0) 
	{
		printf("Client Disconnected\n");
		fflush(stdout);
	}
	else if(read_size < 0)
	{
		printf("Receive Failed\n");
		return -1;
	}
//	shutdown(socket_desc,SHUT_RDWR);
//	shutdown(client_socket,SHUT_RDWR);
	close(socket_desc);
	close(client_socket);

	return 0;
	
}

int main()
{
//	set_top_priority();
//	attach_to_cpu_0();
	
	printf("Launching Server...\n");

	rtt_server();

	printf("Server Terminated\n");

	return 0;
}
