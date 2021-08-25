#include "sort.h"

/**
 * lomuto_partition - use Lomuto partition scheme
 * @array: array of elements
 * @size: size of array
 * @left: index at left
 * @right: index at right
 * Return: index of pivot
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[left];
	int low = left;
	int high = right;
	int tmp;

	while (low < high)
	{
		while (array[high] > pivot)
			high--;
		while (array[low] < pivot)
			low++;
		if (low < high)
		{
			tmp = array[low];
			array[low] = array[high];
			array[high] = tmp;
		}
	}
	return (high);
}

/**
 * quicksort_recurse - quicksort recursively
 * @array: array to sort
 * @size: size of array
 * @low: index at left
 * @high: index at right
 */

void quicksort_recurse(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot;

		pivot = lomuto_partition(array, size, low, high);

		quicksort_recurse(array, size, low, pivot - 1);
		quicksort_recurse(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - uses Lomuto partition scheme to quicksort
 * @array: array of elements to sort
 * @size: size of array to sort
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;

	quicksort_recurse(array, size, 0, size - 1);
}
