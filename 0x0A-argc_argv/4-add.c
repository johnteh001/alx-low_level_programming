#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i, num, sum = 0;

	if (argc == 1)
	{
	printf("0\n");
	return (0);
	}
	for (i = 1; i < argc; i++)
	{
	int j = 0;

	while (argv[i][j] != '\0')
	{
	if (!isdigit(argv[i][j]))
	{
	printf("Error\n");
	return (1);
	}
	j++;
	}
	num = atoi(argv[i]);
	if (num <= 0)
	{
	printf("Error\n");
	return (1);
	}
	sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
