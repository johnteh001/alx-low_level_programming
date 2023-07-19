#include <stdio.h>

/**
 * array_iterator - Executes a function on each element of
 * an array.
 * @array: Pointer to the beginning of the array.
 * @size: Size of the array.
 * @action: Function pointer to the function to be executed on
 * each element.
 * Description: This function iterates through the elements of
 * the array and applies the specified function to each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
