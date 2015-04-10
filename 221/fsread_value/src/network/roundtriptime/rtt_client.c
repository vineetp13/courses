#include "rtt.h"

char send_buf[36];
char recv_buf[36];

int rtt_client()
{
	int socket_desc,client_socket;
	struct sockaddr_in server,client;


	if((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket Error\n");
		return -1;
	}
	printf("Socket Created\n");
/*
	if(inet_pton(AF_INET, "132.239.8.54", &server.sin_addr)<=0)
 	{
 	    printf("inet_pton() error occured\n");
 	    return -1;
 	}
*/
	
	server.sin_addr.s_addr = inet_addr("132.239.10.176");
	server.sin_family = AF_INET;
	server.sin_port = htons(8080);

	if( connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0 )
	{
		printf("Connection Failed\n");
		return -1;
	}
	printf("Connection Successful\n");
	
	if(send(socket_desc, send_buf, strlen(send_buf), 0) < 0)
	{
		printf("Send Error\n");
		return -1;
	}
	printf("Echo Sent\n");
	
/*	bzero(recv_buf,BUF_SIZE);
	if(recv( socket_desc, recv_buf, BUF_SIZE, 0) < 0)
	{
		printf("Receive Error\n");
		return -1;
	}
	printf("Echo Received\n");
*/
/*	if(strcmp(send_buf,recv_buf))
	{
		printf("Incorrect Message Received. Sent : \"%s\" \t Received : \"%s\" \n",send_buf,recv_buf);
		return -1;
	}
	printf("Message Received: %s\n", recv_buf);
*/

//	shutdown(socket_desc,SHUT_RDWR);
	close(socket_desc);
	return 0;
}

int main()
{
	set_top_priority();
	attach_to_cpu_0();
	memset(send_buf,'A',36);
//	rtt_client();
	PM_COUNT(rtt_client(), "Round Trip Time, "O_STR,1);

	return 0;
}
