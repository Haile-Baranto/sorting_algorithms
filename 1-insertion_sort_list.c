#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *insertion_point, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;
		insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			prev = insertion_point->prev;
			next = current->next;

			if (prev != NULL)
				prev->next = current;
			else
				*list = current;

			if (next != NULL)
				next->prev = insertion_point;

			current->prev = prev;
			current->next = insertion_point;

			insertion_point->prev = current;
			insertion_point->next = next;

			print_list(*list);

			insertion_point = current->prev;
		}

		current = temp;
	}
}