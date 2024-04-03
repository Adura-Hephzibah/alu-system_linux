#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/**
 * error - handles error
 * @msg: pointer
 * Return: void
 */
void error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument array
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int sockfd, portno;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	if (argc < 3)
	{
	   fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
	   exit(EXIT_FAILURE);
	}

	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");

	server = gethostbyname(argv[1]);
	if (server == NULL)
	{
		fprintf(stderr, "ERROR, no such host\n");
		exit(EXIT_FAILURE);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,
		 (char *)&serv_addr.sin_addr.s_addr,
		 server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	printf("Connected to %s:%s\n", argv[1], argv[2]);

	close(sockfd);
	return (0);
}
