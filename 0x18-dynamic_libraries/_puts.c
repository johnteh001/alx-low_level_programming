
#include "main.h"

/**
 * _puts - Writes a string to the standard output (stdout)
 * @s: The string to be written
 */
void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}
