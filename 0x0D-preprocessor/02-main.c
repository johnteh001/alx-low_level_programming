#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the name of the
 * file it was compiled from.
 *              It uses the __FILE__ predefined macro
 *              to retrieve the file name.
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
