#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * array_range - creates an array of integers
 * @min: the minimum value (inclusive)
 * @max: the maximum value (inclusive)
 * Return: pointer to the newly created array,
 * NULL on failure or invalid range
 */

void simple_print_buffer(int *buffer, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
	if (i % 10)
	{
	printf(" ");
	}
	if (!(i % 10) && i)
	{
	printf("\n");
	}
	printf("0x%02x", buffer[i]);
	i++;
	}
	printf("\n");
}
/**
 * main - Entry point
 *
 * Return: Always 0
 *
 * Description: This is the main function that demonstrates the usage of the array_range function.
 * It creates an array of integers from 0 to 10 using the array_range function,
 * and then prints the contents of the array using the simple_print_buffer function.
 */
int main(void)
{
	int *a;

	a = array_range(0, 10);
	simple_print_buffer(a, 11);
	free(a);
	return (0);
}
