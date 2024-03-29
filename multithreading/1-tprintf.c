#include "multithreading.h"
/**
 * tprintf - uses the printf family to print out a given formatted string.
 * @format: string to print
 * Return: 0
*/
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (0);
}
