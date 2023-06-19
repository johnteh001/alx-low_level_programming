#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Prints if number is positive, zero or negative
 * Return: Always (Success)
 *
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d positive\n");
	}
	else if (n == 0)
	{
		printf("%d zero\n");
	}
	else
	{
		printf("%d negative\n");
	}
	return (0);
}
