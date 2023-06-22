#include "main.h"

/**
 * _isdigit - check if character is a digit
 * @x: The number to be checked
 * Return: 1 for a character that would be a digit or 0 for any else
 */

int _isdigit(int x)

{
	if (x >= 40 && <= 57)
	{
		return (1);
	}
	return (0);
}
