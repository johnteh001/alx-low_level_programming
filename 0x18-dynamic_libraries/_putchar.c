#include "main.h"

/**
 * _putchar - Writes a character to standard output
 * @c: The character to be written
 *
 * Return: On success, the number of characters written. On error, -1 is
 * returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}
