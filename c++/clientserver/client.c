
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//using namespace std;
main( argc, argv)
int argc;
char **argv;
{
	int sockint, s; /* client socket */
	unsigned short port ; /* port number client will connect to */
	struct sockaddr_in server; /* server address */
	char buf[20*256]; /* data buffer for sending and receiving */

	if( argc != 3 ) { /* check command line arguments */
		fprintf( stderr, "Usage: %s hostname port\n", argv[0] );
		exit(1);
	}

	port = (unsigned short) atoi(argv[2]); /* get the port number */

	strcpy( buf, "Hello there!"); /* create the message */

	/* create stream socket using TCP */
	fprintf(stderr, "Creating datagram socket.\n");
	s = socket(AF_INET, SOCK_STREAM, 0);
	if( s == -1 ) {
		fprintf(stderr, "Socket was not created.\n");
		exit(2);
	}
	else
		fprintf(stderr, "Socket created successfully.\n");

	server.sin_family = AF_INET; /* set up the server name */
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr( argv[1] );

	/* connect to the server */
	if( connect(s, &server, sizeof(server)) < 0) {
		fprintf(stderr, "Failed to connect to socket.\n");
		exit(3);
	}
	char str1[100];
	char str2[100];
	printf("Enter the string to be searched: \n");
	fgets(str1, 100, stdin);
	printf("Enter the file name to be searched: \n");
	fgets(str2, 100,stdin);
	char *mstr1 = strtok(str1,"\n");
	char *mstr2 = strtok(str2,"\n");

	char tmp[256];
	sprintf(tmp,"%s$%s",mstr1,mstr2);
	printf("%s\n",tmp);	
	printf("Sending the message: %s\n", tmp); /* send the message */
	if( send(s, tmp, sizeof(tmp), 0) < 0 ) {
		fprintf(stderr, "Failed to send data to socket.\n");
		exit(4);
	}

	/* receive the echoed message from the server */
	while( recv(s, buf,sizeof(buf), 0) > 0 ) {
		//fprintf(stderr, "Failed to receive data from socket.\n");
		//exit(5);
		printf("%s",buf);
	}
	/*int i=0;
	while(i < 5){
                printf("%s",buff[i]);
                i++;
        }*/
	
	//printf("The message from the server was: %s\n", buf);

	close(s); /* close the socket */
	printf("Client closed successfully\n"); /* successfully exit */
	exit(0);
}
