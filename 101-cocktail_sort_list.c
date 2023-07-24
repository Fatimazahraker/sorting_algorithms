#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *
 *
 *
 */

void swap(listint_t *previ, listint_t *nexti, listint_t **list)
{
	listint_t *before, *after;

	before = previ->prev;
	after = nexti->next;
	if(before)
		before->next = nexti;
	else
		*list = nexti;
	nexti->prev = before;
	previ->prev = nexti;
	nexti->next = previ;
	previ->next = after;
	if (after)
		after->prev = previ;
}

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *end, *start;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	start = *list;
	end = NULL;
	
	do{
		swapped = 0;

		for (current = start; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap(current, current->next, list);
				print_list(*list);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
		end = current->prev;
		swapped = 0;
		for (current = end; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap(current->prev, current, list);
				print_list(*list);
				swapped = 1;
			}
		}
		start = current->next;
	}while (swapped);
}


