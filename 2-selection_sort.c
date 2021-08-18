#include "sort.h"

/**
 * selection_sort - selection sort
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int min_index, temp;
	size_t curr, next;

	if (array && size > 1)
	{
		for (curr = 0; curr < size - 1; curr++)
		{
			/* Assume current/first element is the minimum */
			min_index = curr;

			for (next = curr + 1; next < size; next++)
				/* If next element is smaller than current, update min_index */
				if (array[next] < array[min_index])
					min_index = next;

			/* Swap found minimum with first/current element */
			temp = array[curr];
			array[curr] = array[min_index];
			array[min_index] = temp;
		}
	}
}
