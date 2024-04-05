#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *path = NULL, *line = NULL, *method = NULL, *all_data = NULL, *data = NULL;
	char *brk = "\r\n", *key = NULL, *value = NULL;

	line = strtok(message, brk);
	method = strtok(line, " ");
	path = strtok(NULL, " ");

	printf("Path: %s\n", path);


	all_data = strtok(NULL, "\r\n\r\n");
	if (all_data)
	{
		all_data += strlen("\r\n");
		data = strtok(all_data, "&");

		while (data && method)
		{
			key = strtok(data, "=");
			value = strtok(NULL, "=");

			if (key && value)
			{
				printf("Body param: \"%s\" -> \"%s\"\n", key, value);
			}

			data = strtok(NULL, "&");
		}
	}
	return;
}
