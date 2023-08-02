#include "lists.h"
#include <stdlib.h>
/**
 * free_listint_safe - Frees a listint_t linked list
 * safely (with loop detection).
 * @h: Pointer to the pointer of the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h;
	listint_t *loop_start = NULL;
	listint_t *fast = *h;
	size_t loop_size = 0;
	size_t count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
		loop_start = slow;
		break;
		}
		count++;
	}
	if (fast == NULL || fast->next == NULL)
	{
		while (*h != NULL)
		{
			listint_t *tmp = *h;
			*h = (*h)->next;
			free(tmp);
			count++;
		}
	}
	else
	{
		slow = *h;
		while (slow != fast)
		{
			listint_t *tmp = slow;
			slow = slow->next;
			free(tmp);
			count++;
		}
		fast = fast->next;
		while (fast != loop_start)
		{
			loop_size++;
			fast = fast->next;
		}
		slow = *h;
		while (loop_size > 0)
		{
			listint_t *tmp = slow;
			slow = slow->next;
			free(tmp);
			count++;
			loop_size--;
		}
	}
	*h = NULL;
	return (count);
}
