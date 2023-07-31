#include <stdio.h>
#include "lists.h"
/**
 * print_list - Prints all the elements of a linked list.
 * @h: Pointer to the head of the linked list.
 * Return: The number of nodes in the linked list.
 */

size_t print_list(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
	if (h->str == NULL)
	printf("[0] (nil)\n");
	else
	printf("[%lu] %s\n", h->len, h->str);
	h = h->next;
	node_count++;
	}
	return (node_count);
}
