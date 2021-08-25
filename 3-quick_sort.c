#include "sort.h"

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
	int tmp;

	/* Move pivot to end */
	while (low < high)
	{
		/* Move low element to left side of pivot */
		while (array[low] < pivot)
			low++;
		/* Move high element to right side of pivot */
		while (array[high] > pivot)
			high--;

		/* Swap elements */
		if (low < high)
		{
			tmp = array[low];
			array[low] = array[high];
			array[high] = tmp;
		}
	}

	/* Move pivot to position at end */
	tmp = array[high];
	array[high] = array[low];
	array[low] = tmp;

	print_array(array, size);
	return (low);
}

/**
 * quicksort_recurse - quicksort recursively
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
