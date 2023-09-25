#include <stdbool.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Implements the Bubble sort algorithm to sort an
 * integer array in ascending order.
 * @array: Integer array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
	size_t c, k;
	bool swapped;
	int tempVar;

	if (array == NULL || size == 0)
		return;
	for (c = 0; c < size - 1; ++c)
	{
		swapped = false;

		for (k = 0; k < size - c - 1; ++k)
		{
			if (array[k] > array[k + 1])
			{
				tempVar = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tempVar;
				swapped = true;
				print_array(array, size);
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}
