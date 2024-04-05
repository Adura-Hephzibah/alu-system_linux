#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *path = NULL, *line = NULL, *data = NULL;
	char *brk = "\r\n", *save_ptr = NULL, *key = NULL, *value = NULL;
	char *body = NULL;

	line = strtok(message, brk);
	path = strtok(NULL, " ");
	printf("Path: %s\n", path);

	while ((line = strtok(NULL, brk)) && strlen(line) > 0);

	body = strtok(NULL, "");
	if (body)
	{
		data = strtok_r(body, "&", &save_ptr);
		while (data)
		{
			key = strtok(data, "=");
			value = strtok(NULL, "=");
			printf("Body param: \"%s\" -> \"%s\"\n", key, value);
			data = strtok_r(NULL, "&", &save_ptr);
		}
	}
	return;
}
