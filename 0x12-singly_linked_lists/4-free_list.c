#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "lists.h"
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head - > next;
		free(head - > str);
		free(head);
		head = tmp;
	}
}
