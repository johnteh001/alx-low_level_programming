#include "main.h"

#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of a program.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 * Return: A pointer to a new string, or NULL if it fails.
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len, total_len = 0;

	if (ac == 0 || av == NULL)
	return (NULL);
	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
	total_len++;
	total_len++;
	}
	str = malloc(sizeof(char) * (total_len + 1));

	if (str == NULL)
	return (NULL);
	len = 0;
	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
	{
	str[len] = av[i][j];
	len++;
	}
	str[len] = '\n';
	len++;
	}
	str[len] = '\0';
	return (str);
}
