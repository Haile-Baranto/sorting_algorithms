#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value, i;
	int *count = NULL, *output = NULL;

	if (array == NULL || size < 2)
		return;

	max_value = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	count = (int *)malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
		return;

	output = (int *)malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max_value; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	printf("0");
	for (i = 1; i <= max_value; i++)
	{
		count[i] += count[i - 1];
		printf(", %d", count[i]);
	}
	printf("\n");

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}