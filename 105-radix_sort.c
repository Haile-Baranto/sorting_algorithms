#include "sort.h"

/**
 * find_max - Find the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int find_max(int *array, int size)
{
	int max_value = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * radix_sort_helper - Perform radix sort on the array based
 * on a specific digit.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_sort_helper(int *array, size_t size, int sig, int *buffer)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i != (size_t)-1; i--)
	{
		int digit = (array[i] / sig) % 10;

		buffer[--count[digit]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order using Radix sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Implements the Least Significant Digit (LSD)
 * radix sort algorithm.
 * Prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, sig;
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max_value = find_max(array, size);

	for (sig = 1; max_value / sig > 0; sig *= 10)
	{
		radix_sort_helper(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
