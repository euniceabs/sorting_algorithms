#include "sort.h"

void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - function to get the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
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
 * radix_counting_sort - function to sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort on.
 * @buff: buf to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t g;

	for (g = 0; g < size; g++)
		count[(array[g] / sig) % 10] += 1;

	for (g = 0; g < 10; g++)
		count[g] += count[g - 1];

	for (g = size - 1; (int)g >= 0; g--)
	{
		buff[count[(array[g] / sig) % 10] - 1] = array[g];
		count[(array[g] / sig) % 10] -= 1;
	}

	for (g = 0; g < size; g++)
		array[g] = buff[g];
}

/**
 * radix_sort - function to sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: implements the LSD radix sort algorithm to prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
