#include "sort.h"

/**
 * bubble_sort - Sorts an array of ints in ascending order using Bubble sort
 * @array: array to sort
 * @size: size of array
 * Return: none, prints array after each sorting iteration
 */

void bubble_sort(int *array, size_t size)
{
	size_t tmp; /* store values */
	int is_swapped; /* check if swap has been made */

	/* loop through array */
	for (size_t i = 0; i < size; i++)
	{
		/* re-initalize to 0 after every loop */
		is_swapped = 0;
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			/* compare adjacent elements */
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				/* set is_swapped to 1 to indicate */
				/* that we made a swap */
				is_swapped = 1;
			}
			print_array(array, size);
		}
		/* if no swaps, exit */
		if (!is_swapped)
			break;
	}
}
