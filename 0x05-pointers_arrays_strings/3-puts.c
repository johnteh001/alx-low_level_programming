#include "main.h"

/**
 * _puts - Prints a string
 * @str: The string to print
 * return: void
 */

void _puts(char *str)
{
	for (; *str != '\n'; str++)
	{
	_putchar(*str);
	}
	_putchar('\n');
}
