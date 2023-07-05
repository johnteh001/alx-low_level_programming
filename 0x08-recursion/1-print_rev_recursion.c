#include "main.h"

/**
 * _print_rev_recursion - Print string in reverse
 * @s: String to reverse
 * Return: Nothing
 */

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
	return;
	}
	s++;
	_print_rev_recursion(s);
	s--;
	_putchar(*s);
}
