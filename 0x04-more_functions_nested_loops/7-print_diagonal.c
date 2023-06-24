#include "main.h"

/**
 * print_diagonal - Draws a diagonal line according parameter
 * @n: The number of times to ptint diagonal lines
 * Return: empty
 */

void print_diagonal(int n)

{

	int x, y;

	if (n <= 0)
	{
	_putchar('\n');
	}
	else
	{
	fpr (x = 0; y < n; x++)
	{
	for (y = 0; y < x; y++)
	{
	_putchar(32);
	}
	_putchar(92);
	_putchar('\n');
	}
	}
}
