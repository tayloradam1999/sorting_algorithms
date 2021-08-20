#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithim
 * @list: Doubly linked list to sort
 * Return: Null, prints new list after each iteration of sorting
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *left, *right, *tmp;

	if (list == NULL || *list == NULL)
		return;

	left = *list;

	/* If not end of list, set right to second node */
	if (left->next)
		right = left->next;

	while (right)
	{
		left = right->prev;
		tmp = left;

		/* If current/left node is greater than right node (incorrect) */
		while (left->n > right->n)
		{
			/* Point left's next where it should go, one ahead  */
			left->next = right->next;
			/* Point right's prev where it should go, one behind */
			right->prev = left->prev;
			/* If curr is not first node, point position behind at right */
			if (left->prev)
				left->prev->next = right;
			/* If right is not last node, point position ahead at left */
			if (right->next)
				right->next->prev = left;
			/* Now that behind and ahead are set, point right and left at each other */
			right->next = left;
			left->prev = right;
			/* If left was not head/right is not head now, set right to orig "index" */
			if (right->prev)
				left = right->prev;
			else
			{
				/* If mover is head now, point head to it and print */
				*list = right;
				print_list(*list);
				/* Break because in loop so would print more than once */
				break;
			}
			print_list(*list);
		}
		/* Either out of while loop or never went into it */
		/* If tmp/left node is greater than mover/right node (incorrect) */
		/* move one forward to start again */
		if (tmp->n > right->n)
			right = tmp->next;
		/* If tmp/left node is in correct position but not end of list */
		/* skip everything except this line to start again */
		else if (tmp->next)
			right = tmp->next->next;
		/* If tmp/left node is correct position and end of list */
		/* tmp->next has never been set and is NULL so will end */
		else
			right = tmp->next;
	}
}
