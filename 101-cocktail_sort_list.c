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
