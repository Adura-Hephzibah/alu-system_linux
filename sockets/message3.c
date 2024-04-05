#include "sockets.h"
#include <stdio.h>
#include <string.h>

void requst_breakdown_printout(void *message)
{
	char *body_params = strstr(message, "\r\n\r\n") + 4;
	char *path = strtok(strtok(strchr(message, ' ') + 1, " "), "?");
	char *key, *value;

	printf("Path: %s\n", path);

	for (
		key = strtok(body_params, "="), value = strtok(NULL, "&");
		key && value;
		key = strtok(NULL, "="), value = strtok(NULL, "&")
	)
		printf("Body param: \"%s\" -> \"%s\"\n", key, value);
}
