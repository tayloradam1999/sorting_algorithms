#include "sort.h"
#include <stdio.h>

/**
 * checkSwap - check if left/right nodes need to be swapped and swaps if needed
 * @left: left node (will be smaller)
 * @right: right node (will be larger)
 * @list: linked list to be sorted
 */
void checkSwap(listint_t *left, listint_t *right, listint_t **list)
{
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

		/* If not moving number to head, will have prev to set */
		if (right->prev)
		{
			left = right->prev;
			print_list(*list);
		}
		else
		{
			/* If left is head now, point head of list to same position */
			*list = right;
			print_list(*list);
			/* Break because in loop so would print more than once */
			break;
		}
	}
}

/**
 * insertion_sort_list - Sorts doubly-linked list using insertion sort
 * @list: Doubly linked list to sort
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
		/* Set both left and tmp to same position at left of right */
		left = right->prev;
		/* tmp will not change, while left and right will potentially be swapped */
		/* Used to keep track of current position */
		tmp = left;

		/* Call helper function that checks if nodes need swapped and swaps */
		checkSwap(left, right, list);

		/* If tmp/left node is greater than mover/right node (incorrect) */
		/* Move right one forward to start again */
		if (tmp->n > right->n)
			right = tmp->next;

		/* If tmp/left node is in correct position but not end of list */
		/* Move right forward two to start again */
		else if (tmp->next)
			right = tmp->next->next;

		/* If tmp/left node is correct position and end of list */
		/* tmp->next has never been set and is NULL so will end */
		else
			right = tmp->next;
	}
}
