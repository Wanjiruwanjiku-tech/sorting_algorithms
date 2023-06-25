#include "sort.h"

/**
*insertion_sort_list - Sorts integers in a dobly
*linked list in ascending order using the insertion
*sort algorithm
*@list: Double pointer to the list
*Return: VOID
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *marker;
	/*Check for Null properties in the list*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return; /*Void return*/
	}
	/*Deal with node exchange*/
	current = (*list)->next; /*Initialize current*/
	while (current != NULL)
	{
		temp = current->next;
		marker = current;
		while (marker->prev != NULL && marker->prev->n > current->n)
		{
			marker = marker->prev;
		}
		if (marker != current)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = marker;
			current->prev = marker->prev;
			if (marker->prev != NULL)
				marker->prev->next = current;
			marker->prev = current;

			if (marker == *list)
				*list = current;
			print_list(*list);
		}
		current = temp;
	}
}
