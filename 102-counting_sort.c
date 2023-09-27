#include "sort.h"

/**
 * get_max - function to get the maximum value in
 * an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum int in the array.
 */
int get_max(int *array, int size)
{
	int max, g;

	for (max = array[0], g = 1; g < size; g++)
	{
		if (array[g] > max)
			max = array[g];
	}

	return (max);
}

/**
 * counting_sort - function to sort an array of integers in
 * ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: prints counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, g;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (g = 0; g < (max + 1); g++)
		count[g] = 0;
	for (g = 0; g < (int)size; g++)
		count[array[g]] += 1;
	for (g = 0; g < (max + 1); g++)
		count[g] += count[g - 1];
	print_array(count, max + 1);

	for (g = 0; g < (int)size; g++)
	{
		sorted[count[array[g]] - 1] = array[g];
		count[array[g]] -= 1;
	}

	for (g = 0; g < (int)size; g++)
		array[g] = sorted[g];

	free(sorted);
	free(count);
}
