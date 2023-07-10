#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: On success, a pointer to the concatenated string.
 *         On failure, NULL.
 */

char *str_concat(char *s1, char *s2)
{
	char *concat;
	size_t len1 = 0, len2 = 0;
	size_t i, j;

	if (s1 != NULL)
	{
	while (s1[len1] != '\0')
	len1++;
	}
	if (s2 != NULL)
	{
	while (s2[len2] != '\0')
	len2++;
	}
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
	return (NULL);
	for (i = 0; i < len1; i++)
	concat[i] = s1[i];
	for (j = 0; j < len2; j++)
	concat[len1 + j] = s2[j];
	concat[len1 + len2] = '\0';
	return (concat);
}
