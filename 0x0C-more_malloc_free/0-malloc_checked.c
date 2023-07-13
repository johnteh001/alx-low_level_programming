#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: The number of bytes to allocate.
 * Return: Pointer to the allocated memory.
 *         If malloc fails, terminates the program
 *         with a status value of 98.
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
	printf("Memory allocation failed\n");
	exit(98);
	}
	return (ptr);
}
