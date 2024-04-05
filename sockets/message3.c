#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *request_line = NULL, *header_line = NULL, *body = NULL;
	char *brk = "\r\n";
	char *saveptr1, *saveptr2;
	char method[8], path[32], version[16];
	char key[32], value[64];
	char *param;

	request_line = strtok_r(message, brk, &saveptr1);

	sscanf(request_line, "%s %s %s", method, path, version);
	printf("Path: %s\n", path);

	header_line = strtok_r(NULL, brk, &saveptr1);

	strtok_r(NULL, brk, &saveptr1);

	body = strtok_r(NULL, "", &saveptr1);

	param = strtok_r(body, "&", &saveptr2);
	while (param)
	{
		sscanf(param, "%[^=]=%s", key, value);
		printf("Body param: \"%s\" -> \"%s\"\n", key, value);
		param = strtok_r(NULL, "&", &saveptr2);
	}

}
