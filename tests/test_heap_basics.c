/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heap_basics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:46:46 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 19:46:51 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_heap		heap;
	t_request	a;
	t_request	b;
	t_request	c;

	a.coder_id = 1;
	a.key = 100;
	b.coder_id = 2;
	b.key = 50;
	c.coder_id = 3;
	c.key = 100;
	assert_equal("b antes de a", request_before(&b, &a), 1);
	assert_equal("a antes de b", request_before(&a, &b), 0);
	assert_equal("empate: 1 antes de 3", request_before(&a, &c), 1);
	assert_equal("empate: 3 antes de 1", request_before(&c, &a), 0);
	assert_equal("init", heap_init(&heap, 5), 1);
	assert_equal("size", heap.size, 0);
	assert_equal("capacity", heap.capacity, 5);
	heap_destroy(&heap);
	return (0);
}
