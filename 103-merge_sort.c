#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge_partition(size_t left_index, size_t right_index,
int *array, int *temp);
void merge(size_t left_index, size_t middle_index, size_t right_index,
int *destination, int *source);

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	merge_partition(0, size, array, temp);

	free(temp);
}

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @left_index: The lowest index of the left subarray.
 * @middle_index: The middle index separating the two subarrays.
 * @right_index: The highest index of the right subarray.
 * @destination: The destination array for the merged subarrays.
 * @source: The source array containing the subarrays to merge.
 */
void merge(size_t left_index, size_t middle_index, size_t right_index,
int *destination, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + left_index, middle_index - left_index);
	printf("[right]: ");
	print_array(source + middle_index, right_index - middle_index);

	i = left_index;
	j = middle_index;
	k = left_index;

	while (k < right_index)
	{
		if (i < middle_index && (j >= right_index || source[i] <= source[j]))
			destination[k++] = source[i++];
		else
			destination[k++] = source[j++];
	}

	printf("[Done]: ");
	print_array(destination + left_index, right_index - left_index);
}

/**
 * merge_partition - Recursively divides the array and merges the subarrays.
 * @left_index: The lowest index of the subarray.
 * @right_index: The highest index of the subarray.
 * @array: The array to sort.
 * @temp: The temporary array for merging.
 */
void merge_partition(size_t left_index, size_t right_index,
int *array, int *temp)
{
	size_t middle_index;

	if (right_index - left_index < 2)
		return;

	middle_index = (left_index + right_index) / 2;
	merge_partition(left_index, middle_index, array, temp);
	merge_partition(middle_index, right_index, array, temp);
	merge(left_index, middle_index, right_index, array, temp);

	for (middle_index = left_index; middle_index < right_index; middle_index++)
		temp[middle_index] = array[middle_index];
}
