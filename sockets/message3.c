#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *path = NULL, *all_data = NULL, *data = NULL;
	char *key = NULL, *value = NULL;

	path = strtok(NULL, " ");

	printf("Path: %s\n", path);

	all_data = strtok(NULL, "");
	if (all_data != NULL)
	{
		printf("Body params:\n");
		data = strtok(all_data, "&");
		while (data)
		{
			key = strtok(data, "=");
			value = strtok(NULL, "=");
			printf("\"%s\" -> \"%s\"\n", key, value);
			data = strtok(NULL, "&");
		}
	}
}

int main(void)
{
	int sockid = 0, sockid_c = 0, client_size = 0, server_size = 0;
	struct sockaddr_in client;
	struct sockaddr_in addrport;
	char message[1024];
	char response[] = "HTTP/1.1 200 OK\r\n\r\n";
	size_t count = recv(sockid_c, message, sizeof(message), 0);

	sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	addrport.sin_family = AF_INET;
	addrport.sin_addr.s_addr = INADDR_ANY;
	addrport.sin_port = htons(8080);
	server_size = sizeof(addrport);
	bind(sockid, (struct sockaddr *) &addrport, server_size);
	printf("Server listening on port 8080\n");

	while (1)
	{
		listen(sockid, 8);
		client_size = sizeof(client);
		sockid_c = accept(sockid, (struct sockaddr *) &client, (socklen_t *) &client_size);
		printf("Client connected: %s\n", inet_ntoa(client.sin_addr));

		if (count > 0)
		{
			message[count] = '\0';
			printf("Raw request: \"%s\"\n", message);
			send(sockid_c, response, strlen(response), 0);
			requst_breakdown_printout((void *)message);
		}

		close(sockid_c);
	}

	return (0);
}
