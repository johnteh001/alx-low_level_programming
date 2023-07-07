#include <stdio.h>

/**
 * main - prints programs name
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 (Success)
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	char *program_name = argv[0];

	printf("%s\n", program_name);
	return (0);
}
