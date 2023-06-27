#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: A pointer to the array to be sorted
 * @size: The size of the array to sorted
 * Description: You’re expected to print the array
 * after each time you swap two elements
 * Best, average and worest case coplexity of the algorithms
 * are written at 0-O file each per line respectively
*/
void bubble_sort(int *array, size_t size)
{
	size_t step;
	size_t i;
	int temp;

	if (size >= 2)
	{
		for (step = 0; step < (size - 1); step++)
		{
			for (i = 0; i < size - step - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					/*To print every time there is swaping of the elements*/
					print_array(array, size);
				}
			}
		}
	}
}
