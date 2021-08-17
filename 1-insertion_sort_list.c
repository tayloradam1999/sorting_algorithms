#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithim
 * @list: Doubly linked list to sort
 * Return: Null, prints new list after each iteration of sorting
 */
void insertion_sort_list(listint_t **list)
{
	int n;
	listint_t *cursor = *list;
	listint_t *ptr, *tmp;

	if (cursor->next == NULL || !cursor)
		return;
	while (cursor != NULL)
	{
		n = 0;
		ptr = cursor;
		tmp = cursor->prev;
		cursor = cursor->next;
		while (tmp != NULL && tmp->n > ptr->n)
			n++, tmp = tmp->prev;
		if (n)
		{
			ptr->prev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			if (tmp == NULL)
			{
				tmp = *list;
				ptr->prev = NULL;
				ptr->next = tmp;
				ptr->next->prev = ptr;
				*list = ptr;
			}
			else
			{
				tmp = tmp->next;
				tmp->prev->next = ptr;
				ptr->prev = tmp->prev;
				tmp->prev = ptr;
				ptr->next = tmp;
			}
			print_list(*list);
		}
	}
}
