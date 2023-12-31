#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * hash_table_create - Create a sorted hash table
 * @size: Size of the array
 * Return: A pointer to the created hash table, NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *sht;

	sht = malloc(sizeof(hash_table_t));
	if (sht == NULL)
		return (NULL);
	sht->size = size;
	sht->array = calloc(size, sizeof(hash_node_t *));
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}
	sht->shead = NULL;
	sht->stail = NULL;
	return (sht);
}
/**
 * hash_table_set - Insert a key/value pair into the sorted hash table
 * @ht: Hash table
 * @key: Key string
 * @value: Value string
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current, *prev;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->shead;
	prev = NULL;
	while (current != NULL && strcmp(key, current->key) > 0)
	{
		prev = current;
		current = current->snext;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	if (prev == NULL)
	{
		new_node->snext = ht->shead;
		ht->shead = new_node;
	}
	else
	{
		new_node->snext = current;
		prev->snext = new_node;
	}
	return (1);
}
/**
 * hash_table_get - Retrieve a value associated with a key
 * @ht: Hash table
 * @key: Key string
 * Return: Value associated with the key, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(key, current->key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
/**
 * hash_table_print - Print a sorted hash table
 * @ht: Hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;

	if (ht == NULL)
		return;
	current = ht->shead;
	printf("{");
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
		if (current != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * hash_table_print_rev - Print a sorted hash table in reverse order
 * @ht: Hash table
 */
void hash_table_print_rev(const hash_table_t *ht)
{
	hash_node_t *current;

	if (ht == NULL)
		return;
	current = ht->stail;
	printf("{");
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
		if (current != NULL)
			 printf(", ");
	}
	printf("}\n");
}
/**
 * hash_table_delete - Delete a sorted hash table
 * @ht: Hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current, *temp;

	if (ht == NULL)
		return;
	current = ht->shead;
	while (current != NULL)
	{
		temp = current;
		current = current->snext;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	free(ht->array);
	free(ht);
}
