#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - SWAP
 * @list: list
 * @node1: list
 * @node2: list
 * return: void
 */

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	node1->prev = node2, node2->next = node1;
	if (!node2->prev)
		*list = node2;
	print_list(*list);
}
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	start = *list;
	end = NULL;
	
	do{
		swapped = 0;
		printf("before");
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap(start, start->next, list);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
			printf("!inside1");
		}
		if (swapped == 0)
			break;
		end = start;
		start = end->prev;
		swapped = 0;
		while (start->prev != end)
		{
			if (start->n > start->next->n)
			{
				swap(start, start->next, list);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
			printf("inside2");
		}
		end = end->prev;
		printf("after");
	}while (swapped);
}

