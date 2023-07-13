#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @nmemb: Number of elements in the array
 * @size: Size of each element
 *
 * Return: Pointer to the allocated memory, or NULL if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
	return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	return (NULL);
	memset(ptr, 0, nmemb * size);
	return (ptr);
}
