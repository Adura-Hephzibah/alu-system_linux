#include "multithreading.h"
/**
 * thread_entry - function that will serve as the entry point to a new thread
 * @arg: holds the address of a string that must be printed and
 * followed by a new line.
 * Return: None
*/
void *thread_entry(void *arg)
{
	printf("%s\n", (char *)arg);
	pthread_exit(NULL);
	return (0);
}
