#include "sort.h"

#define UP 1
#define DOWN 0

/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge_bitonic_sequence - Sort a bitonic sequence
 * inside an array of integers.
 * @arr: An array of integers.
 * @sz: The size of the array.
 * @st: The starting index of the sequence in the array to sort.
 * @sq: The size of the sequence to sort.
 * @flw: The direction to sort in.
 */
void merge_bitonic_sequence(int *arr, size_t sz,
size_t st, size_t sq, char flw)
{
	size_t i, jump = sq / 2;

	if (sq > 1)
	{
		for (i = st; i < st + jump; i++)
		{
			if ((flw == UP && arr[i] > arr[i + jump]) ||
				(flw == DOWN && arr[i] < arr[i + jump]))
				swap_integers(arr + i, arr + i + jump);
		}
		merge_bitonic_sequence(arr, sz, st, jump, flw);
		merge_bitonic_sequence(arr, sz, st + jump, jump, flw);
	}
}

/**
 * build_bitonic_sequence - Convert an array of integers
 * into a bitonic sequence.
 * @arr: An array of integers.
 * @sz: The size of the array.
 * @st: The starting index of a block of the building bitonic sequence.
 * @sq: The size of a block of the building bitonic sequence.
 * @flw: The direction to sort the bitonic sequence block in.
 */
void build_bitonic_sequence(int *arr, size_t sz,
size_t st, size_t sq, char flw)
{
	size_t cut = sq / 2;
	char *str = (flw == UP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, sz, str);
		print_array(arr + st, sq);

		build_bitonic_sequence(arr, sz, st, cut, UP);
		build_bitonic_sequence(arr, sz, st + cut, cut, DOWN);
		merge_bitonic_sequence(arr, sz, st, sq, flw);

		printf("Result [%lu/%lu] (%s):\n", sq, sz, str);
		print_array(arr + st, sq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @arr: An array of integers.
 * @sz: The size of the array.
 *
 * Description: Prints the array after each swap. Only
 * works for size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *arr, size_t sz)
{
	if (arr == NULL || sz < 2)
		return;

	build_bitonic_sequence(arr, sz, 0, sz, UP);
}
