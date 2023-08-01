#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given
 * position in a listint_t linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @idx: The index where the new node should be added
 * (starting from 0).
 * @n: The data (n) to be assigned to the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count = 0;
	listint_t *current, *new_node;

	if (head == NULL)
		return (NULL);
	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);
		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	current = *head;
	while (current != NULL)
	{
		if (count == idx - 1)
		{
			new_node = malloc(sizeof(listint_t));
			if (new_node == NULL)
				return (NULL);
			new_node->n = n;
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
		count++;
	}
	return (NULL);
}
