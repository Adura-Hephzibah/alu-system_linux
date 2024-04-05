#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *path = NULL, *line = NULL, *data = NULL;
	char *brk = "\r\n", *save_ptr1 = NULL, *save_ptr2 = NULL, *key = NULL, *value = NULL;
	char *body = NULL;

	line = strtok_r(message, brk, &save_ptr1);
	path = strtok_r(NULL, " ", &save_ptr2);
	printf("Path: %s\n", path);

	while ((line = strtok_r(NULL, brk, &save_ptr1)) && strlen(line) > 0);

	body = strtok_r(NULL, "", &save_ptr1);
	if (body)
	{
		data = strtok_r(body, "&", &save_ptr2);
		while (data)
		{
			key = strtok(data, "=");
			value = strtok(NULL, "=");
			printf("Body param: \"%s\" -> \"%s\"\n", key, value);
			data = strtok_r(NULL, "&", &save_ptr2);
		}
	}
	return;
}
