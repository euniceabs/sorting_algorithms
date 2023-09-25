#include "sort.h"
#include <stdio.h>


/**
 * insertion_sort_list - this function is used to sort a doubly linked list
 * of integers in ascending order inculcating the Insertion sort algorithm
 * @list: A double pointer to the head of the list
 *
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *tempVar;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		tempVar = key->prev;

		while (tempVar != NULL && tempVar->n > key->n)
		{
			tempVar->next = key->next;
			if (key->next != NULL)

				key->next->prev = tempVar;
			key->prev = tempVar->prev;
			if (tempVar->prev != NULL)
				tempVar->prev->next = key;
			else
				*list = key;

			tempVar->prev = key;
			key->next = tempVar;

			tempVar = key->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
