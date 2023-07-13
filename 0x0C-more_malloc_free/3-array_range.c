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

int *array_range(int min, int max)
{
	int *arr, size, i;

	if (min > max)
	return (NULL);
	size = max - min + 1;
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	arr[i] = min++;
	return (arr);
}
