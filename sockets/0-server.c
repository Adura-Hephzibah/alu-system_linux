#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345

/**
 * main - opens an IPv4/TCP socket, and listens to traffic on port 12345
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	int sockfd;
	struct sockaddr_in serv_addr;

	/* Create socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		exit(1);

	/* Initialize socket structure */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	/* Bind the host address */
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		exit(1);

	/* Start listening for the clients */
	listen(sockfd, 5);
	printf("Server is listening on port %d\n", PORT);

	/* The server should run indefinitely */
	while (1)
		;

	return (0);
}
