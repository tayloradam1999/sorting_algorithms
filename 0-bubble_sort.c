#include "sort.h"

/**
 * swap - swaps two elements
 * @x: one element two swap
 * @y: second element two swap
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Sorts an array of ints in ascending order using Bubble sort
 * @array: array to sort
 * @size: size of array
 * Return: none, prints array after each sorting iteration
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
