#include "sort.h"


/**
 * swap_items - Function to swap two elements in an array.
 * @array: The array to perform the swap on.
 * @l: The index of the first element to swap.
 * @r: The index of the second element to swap.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tempVar;

	if (array != NULL)
	{
		tempVar = array[l];
		array[l] = array[r];
		array[r] = tempVar;
	}
}

/**
 * lomuto_partition - Function to partition an array using Lomuto's scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 * @size: The size of the array.
 * Return: The index of the pivot element after partitioning.
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t c = low - 1;
	size_t k;

	for (k = low; k < high; k++)
	{
		if (array[k] <= pivot)
		{
			c++;
			if (c != k)
			{
				swap_items(array, c, k);
				print_array(array, size);
			}
		}
	}

	if ((c + 1) != high)
	{
		swap_items(array, c + 1, high);
		print_array(array, size);
	}

	return (c + 1);
}

/**
 * quick_sort_lomuto - Function to sort a sub-array using the
 * quicksort algorithm with Lomuto's partition scheme.
 * @array: The array containing the sub-array to sort.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 * @size: The size of the array.
 */

void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_idex;

	if (low < high)
	{
		pivot_idex = lomuto_partition(array, low, high, size);

	if (pivot_idex > 0)
		quick_sort_lomuto(array, low, pivot_idex - 1, size);
	quick_sort_lomuto(array, pivot_idex + 1, high, size);
	}
}

/**
 * quick_sort - Function to sort an array using the quicksort algorithm
 * with Lomuto's partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
	{
		quick_sort_lomuto(array, 0, size - 1, size);
	}
}
