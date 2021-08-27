#include "sort.h"

/**
 * lomuto_partition - use Lomuto partition scheme to place pivot
 * @array: array of elements
 * @size: size of array
 * @low: index of lower element
 * @high: index of higher element
 * Return: new index of pivot
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, x, new, tmp;

	/* Temporarily assign pivot to last element */
	pivot = array[high];
	/* Temporarily assign new to first index */
	new = low;

	for (x = low; x <= high - 1; x++)
	{
		if (array[x] <= pivot)
		{
			/* If element less than pivot, swap positions until smaller all on left */
			tmp = array[new];
			array[new] = array[x];
			array[x] = tmp;

			/* Print if change made in previous swap */
			if (x != new)
				print_array(array, size);
			/* If enters loop, there is a number smaller than pivot */
			new++;
		}
	}

	/* Put pivot into place directly after all numbers lower than it */
	tmp = array[new];
	array[new] = array[high];
	array[high] = tmp;

	/* Print if pivot swapped */
	if (new != high)
		print_array(array, size);

	/* Return new index of pivot */
	return (new);
}

/**
 * quicksort_recurse - quicksort recursively by dividing array in half
 * @array: array to sort
 * @size: size of array
 * @low: lower of two numbers
 * @high: higher of two numbers
 */

void quicksort_recurse(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot;

		/* Partitions array by pivot and saves pivot index */
		pivot = lomuto_partition(array, size, low, high);

		/* Sort left/low side of pivot */
		quicksort_recurse(array, size, low, pivot - 1);
		/* Sort right/high side of pivot */
		quicksort_recurse(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - handles edge cases and calls function that quicksorts
 * @array: array of elements to sort
 * @size: size of array to sort
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;

	quicksort_recurse(array, size, 0, size - 1);
}
