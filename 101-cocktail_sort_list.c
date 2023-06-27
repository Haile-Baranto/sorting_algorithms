#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1 = node1->prev;
	listint_t *next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	else
		*list = node2;

	node2->prev = prev1;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next2;

	if (next2)
		next2->prev = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	int swapped = 1;

	while (swapped)
	{
		swapped = 0;
		while (start && start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		while (start && start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->prev;
			}
		}
	}
}
