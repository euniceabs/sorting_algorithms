#include <stdio.h>
#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: Aarray to be sorted
 * @size: Size of the array
 *
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t c, k, min_idex;
	int tempVar;

	if (array == NULL || size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		min_idex = c;

		for (k = c + 1; k < size; k++)
		{
			if (array[k] < array[min_idex])
				min_idex = k;
		}

		if (min_idex != c)
		{
			tempVar = array[c];
			array[c] = array[min_idex];
			array[min_idex] = tempVar;

			for (k = 0; k < size; k++)
				printf("%d%s", array[k], (k == size - 1) ? "\n"
						: ", ");
		}
	}
}
