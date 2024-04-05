#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 256

/**
 * main - opens an IPv4/TCP socket, and listens to traffic on port 12345
 * Return: 0 on success, 1 on failure
 */
int main()
{
	int sockfd, newsockfd;
	socklen_t clilen;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		exit(1);


	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);


	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		exit(1);

	listen(sockfd, 5);
	printf("Server listening on port %d\n", PORT);

	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	if (newsockfd < 0)
		exit(1);

	printf("Client connected: %s\n", inet_ntoa(cli_addr.sin_addr));

	/*Clear the buffer*/
	bzero(buffer, BUFFER_SIZE);

	/* Read the message from the client */
	n = read(newsockfd, buffer, BUFFER_SIZE - 1);
	if (n < 0)
		exit(1);

	printf("Message received: \"%s\"\n", buffer);

	close(newsockfd);
	close(sockfd);

	return (0);
}
