#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: The memory area
 * @b: The byte to fill the memory area with
 * @n: The number of bytes to fill
 *
 * Return: The pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *p = s;

	while (n-- > 0)
		*s++ = b;
	return (p);
}
