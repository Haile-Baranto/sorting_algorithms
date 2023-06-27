#include "sort.h"

/**
 * swap_integers - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition_hoare - Partitions a subset of an array according to the Hoare
 *                   partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int partition_hoare(int *array, size_t size, int left, int right)
{
	int pivot, i, j;

	pivot = array[right];
	for (i = left - 1, j = right + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap_integers(array + i, array + j);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * sort_hoare - Implements the quicksort algorithm using the Hoare partition
 *              scheme through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 */
void sort_hoare(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = partition_hoare(array, size, left, right);
		sort_hoare(array, size, left, partition - 1);
		sort_hoare(array, size, partition, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    quicksort algorithm with the Hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, size, 0, size - 1);
}
