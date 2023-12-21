#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 * @str: Input string to be hashed
 * Return: Computed hash value
 *
 * Description: The djb2 algorithm is a simple, non-cryptographic hash
 * function created by Daniel J. Bernstein. It efficiently generates hash
 * values by iterating over characters in the input string and updating
 * the hash using the formula: hash = ((hash << 5) + hash) + c.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}
