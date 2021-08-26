#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - use Lomuto partition scheme to move pivot to last index
 * @array: array of elements
 * @size: size of array
 * @low: index of lower element
 * @high: index of higher element
 * Return: new index of pivot
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	/* Assign pivot to last element */
	int pivot = array[high];
	int x, tmp;

	/* Move pivot to end of array */
	for (x = low; x < high; x++)
	{
		/* If element is less than pivot, swap it with lower element */
		if (array[x] < pivot)
		{
			tmp = array[x];
			array[x] = array[low];
			array[low] = tmp;
			low++;
		}
	}
	if (low != x && array[0] != array[low])
		print_array(array, size);

	/* Swap pivot with last element */
	if (low != x)
	{
		tmp = array[low];
		array[low] = array[high];
		array[high] = tmp;

		print_array(array, size);
	}

	return (low);
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

		/* Assigns pivot based on Lomuto partition scheme */
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
