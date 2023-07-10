#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 * @str: The string to duplicate.
 * Return: On success, a pointer to the duplicated string.
 *         On failure, NULL if str is NULL or if insufficient
 *         memory was available.
 */

char *_strdup(char *str)
{
	char *dup;
	size_t len = 0;
	size_t i;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}
