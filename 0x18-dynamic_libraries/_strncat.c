#include "main.h"

/**
 * _strncat - Concatenates two strings with a specified length
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of characters to concatenate
 *
 * Return: The pointer to the destination buffer.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *p = dest;

	while (*dest)
		dest++;
	while
		(n-- > 0 && (*dest++ = *src++));
	return (p);
}
