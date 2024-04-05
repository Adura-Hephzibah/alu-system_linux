#include "sockets.h"

void requst_breakdown_printout(void *message)
{
	char *line = NULL, *user_agent_ptr = NULL, *key = NULL, *value = NULL;
	char *brk = "\r\n";

	line = strtok_r(message, brk, &user_agent_ptr);
	line = strtok_r(NULL, brk, &user_agent_ptr);
	while (line)
	{
		key = strtok(line, ":");
		value = strtok(NULL, "\t");
		printf("Header: \"%s\" -> \"%s\"\n", key, value + 1);
		line = strtok_r(NULL, brk, &user_agent_ptr);
	}

}
