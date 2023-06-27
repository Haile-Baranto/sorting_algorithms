#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using selection sort
 * @array: The array whose elements to be sorted
 * @size: Size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t step;
	size_t i;
	size_t min_index;
	int temp;
	int isSwapped;

	if (size >= 2)
	{
		for (step = 0; step < size - 1; step++)
		{
			min_index = step;
			isSwapped = 0;
			for (i = step + 1; i < size; i++)
			{
				if (array[min_index] > array[i])
				{
					min_index = i;
					isSwapped = 1;
				}
			}
			/* Swapping */
			temp = array[min_index];
			array[min_index] = array[step];
			array[step] = temp;
			if (isSwapped)
			{
				/* Printing the array after the first swapping */
				print_array(array, size);
			}
		}
	}
}
