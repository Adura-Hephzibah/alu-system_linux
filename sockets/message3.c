#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *path = NULL, *line = NULL, *method = NULL, *all_data = NULL, *data = NULL;
	char *brk = "\r\n", *req_type = NULL, *save_ptr = NULL, *key = NULL, *value = NULL;
	char *body = NULL;

	line = strtok(message, brk);
	method = strtok(line, " ");
	path = strtok(NULL, " ");
	req_type = strtok(NULL, "\r\n");
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
