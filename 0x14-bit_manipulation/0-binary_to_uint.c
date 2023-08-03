#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to the binary string.
 * Return: The converted number, or 0 if there is an invalid
 * character in the string or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);
	for (; *b != '\0'; b++)
	{
		if (*b == '0')
		{
		result <<= 1;
		}
		else if (*b == '1')
		{
		result <<= 1;
		result |= 1;
		}
		else
		{
		return (0);
		}
	}
	return (result);
}
