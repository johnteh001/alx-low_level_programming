#include "hash_tables.h"
#include <stdlib.h>

/**
 * key_index - Get the index of a key in a hash table array
 * @key: The key string
 * @size: The size of the hash table array
 * Return: The index at which the key should be stored
 *
 * Description: This function uses the djb2 hash algorithm to compute
 * the hash value for the input key. It then returns the index at which
 * the corresponding key/value pair should be stored in the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
