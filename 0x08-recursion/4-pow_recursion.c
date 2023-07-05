#include "main.h"

/**
 * _pow_recursion - Returns value of x raised to power of y
 * @x: Value to multiply
 * @y: Number of times to multiply value
 * Return: Value multiplied y times
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	return (-1);
	if (y == 0)
	return (1);

	return (x * _pow_recursion(x, y - 1));
}
