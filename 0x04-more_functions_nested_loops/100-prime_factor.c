#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 * @n: The number
 * Return: The largest prime factor of n
 */

long largest_prime_factor(long n)
{
	long largest_factor = -1;
	long i;

	while (n % 2 == 0)
	{
	largest_factor = 2;
	n /= 2;
	}
	for (i = 3; i <= sqrt(n); i += 2)
	{
	while (n % i == 0)
	{
	largest_factor = i;
	n /= i;
	}
	}
	if (n > 2)
	largest_factor = n;
	return (largest_factor);
}

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */

int main(void)
{
	long number = 612852475143;
	long largest_factor = largest_prime_factor(number);

	printf("%ld\n", largest_factor);
	return (0);
}
