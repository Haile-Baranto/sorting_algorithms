#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: First integer.
 * @b: Second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Heapify a subtree rooted at given index.
 * @array: Array to heapify.
 * @size: Size of the array.
 * @root: Root index.
 * @max: Size of the heap.
 */
void heapify(int *array, size_t size, size_t root, size_t max)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < max && array[left] > array[largest])
		largest = left;

	if (right < max && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using Heap sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	/* Build max heap */
	for (i = size / 2 - 1; (int)i >= 0; i--)
		heapify(array, size, i, size);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
