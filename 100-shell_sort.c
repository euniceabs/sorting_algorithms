#include "sort.h"
#include <stdio.h>


/**
 * _swap - swaps two values in an array.
 * @array: The array in which values need to be swapped.
 * @c: Index of the first value.
 * @k: Index of the second value.
 */
void _swap(int *array, int c, int k)
{
	int tempVar = array[c];

	array[c] = array[k];
	array[k] = tempVar;
}

/**
 * shell_sort - Sorts an array using the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t interval, c, k;

	if (array == NULL || size < 2)
		return;
	for (interval = 1; interval < size / 3; interval = interval * 3 + 1)
		;

	while (interval > 0)
	{
		for (c = interval; c < size; c++)
		{
			for (k = c; k >= interval && array[k - interval] > array[k]; k -= interval)
				_swap(array, k, k - interval);
		}
		interval /= 3;
		print_array(array, size);
	}
}
