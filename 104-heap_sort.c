#include "sort.h"

void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);

/**
 * swap_ints - function to swap two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - function to turn a binary tree into a complete binary heap.
 * @array: array of integers representing a binary tree.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - function to sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: implements the sift-down heap sort
 * algorithm to prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int g;

	if (array == NULL || size < 2)
		return;

	for (g = (size / 2) - 1; g >= 0; g--)
		max_heapify(array, size, size, g);

	for (g = size - 1; g > 0; g--)
	{
		swap_ints(array, array + g);
		print_array(array, size);
		max_heapify(array, size, g, 0);
	}
}
