/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:45:26 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 20:30:58 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static	void	swap_requests(t_request *a, t_request *b)
{
	t_request	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static	void	sift_up(t_heap *heap, int i)
{
	int	parent;

	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (!request_before(&heap->items[i], &heap->items[parent]))
			break ;
		swap_requests(&heap->items[i], &heap->items[parent]);
		i = parent;
	}
}

static	void	sift_down(t_heap *heap, int i)
{
	int	child;

	while (2 * i + 1 < heap->size)
	{
		child = 2 * i + 1;
		if (child + 1 < heap->size
			&& request_before(&heap->items[child + 1],
				&heap->items[child]))
			child++;
		if (!request_before(&heap->items[child], &heap->items[i]))
			break ;
		swap_requests(&heap->items[i], &heap->items[child]);
		i = child;
	}
}

int	heap_push(t_heap *heap, t_request request)
{
	if (heap->size == heap->capacity)
		return (0);
	heap->items[heap->size] = request;
	heap->size++;
	sift_up(heap, heap->size - 1);
	return (1);
}

int	heap_pop(t_heap *heap, t_request *out)
{
	if (heap->size == 0)
		return (0);
	*out = heap->items[0];
	heap->size--;
	if (heap->size > 0)
	{
		heap->items[0] = heap->items[heap->size];
		sift_down(heap, 0);
	}
	return (1);
}
