/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:31:43 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 20:58:51 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	push(t_heap *heap, int id, long key)
{
	t_request	request;

	request.coder_id = id;
	request.key = key;
	heap_push(heap, request);
}

int	main(void)
{
	t_heap		heap;
	t_request	out;

	heap_init(&heap, 5);
	push(&heap, 1, 30);
	push(&heap, 2, 10);
	push(&heap, 3, 20);
	push(&heap, 4, 10);
	push(&heap, 5, 40);
	assert_equal("cheio", heap.size, 5);
	assert_equal("peek", heap_peek(&heap)->coder_id, 2);
	assert_equal("peek nao remove", heap.size, 5);
	out.coder_id = 9;
	out.key = 1;
	assert_equal("push alem da capacidade", heap_push(&heap, out), 0);
	heap_pop(&heap, &out);
	assert_equal("1o: key 10, id 2", out.coder_id, 2);
	heap_pop(&heap, &out);
	assert_equal("2o: key 10, id 4", out.coder_id, 4);
	heap_pop(&heap, &out);
	assert_equal("3o: key 20, id 3", out.coder_id, 3);
	heap_pop(&heap, &out);
	assert_equal("4o: key 30, id 1", out.coder_id, 1);
	heap_pop(&heap, &out);
	assert_equal("5o: key 40, id 5", out.coder_id, 5);
	assert_equal("pop no vazio", heap_pop(&heap, &out), 0);
	assert_equal("peek vazio", heap_peek(&heap) == NULL, 1);
	heap_destroy(&heap);
	return (0);
}
