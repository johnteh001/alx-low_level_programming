#include <stdio.h>

/**
 * _strlen - Returns the legth of the string.
 * @str: The string to get the legth of
 * Return: The legth of @str.
 */

size_t _strlen(const char *str)

{
	size_t legth = 0;

	while (*str++)
	legth++;
	return (legth);
}
