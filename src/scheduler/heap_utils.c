/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:45:04 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 16:50:19 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	heap_init(t_heap *heap, int capacity)
{
	if (capacity <= 0)
		return (0);
	heap->items = malloc(sizeof(*heap->items) * capacity);
	if (heap->items == NULL)
		return (0);
	heap->size = 0;
	heap->capacity = capacity;
	return (1);
}

void	heap_destroy(t_heap *heap)
{
	free(heap->items);
	heap->items = NULL;
	heap->size = 0;
	heap->capacity = 0;
}

t_request	*heap_peek(t_heap *heap)
{
	if (heap->size == 0)
		return (NULL);
	return (&heap->items[0]);
}

void	heap_remove(t_heap *heap, int coder_id)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < heap->size)
	{
		if (heap->items[i].coder_id != coder_id)
			heap->items[count++] = heap->items[i];
		i++;
	}
	heap->size = 0;
	i = 0;
	while (i < count)
	{
		heap_push(heap, heap->items[i]);
		i++;
	}
}
