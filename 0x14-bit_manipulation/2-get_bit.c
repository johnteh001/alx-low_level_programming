#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to check the bit in.
 * @index: The index of the bit to get (starting from 0).
 *
 * Return: The value of the bit at the given index (0 or 1),
 *         or -1 if an error occurred (if index is too large).
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	mask = 1UL << index;
	return ((n & mask) ? 1 : 0);
}
