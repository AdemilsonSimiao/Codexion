/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_dongles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 08:11:02 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 20:47:46 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	int		i;

	data.config.number_of_coders = 3;
	data.config.dongle_cooldown = 100;
	assert_equal("retorno", init_dongles(&data), 1);
	i = 0;
	while (i < 3)
	{
		assert_equal("em uso", data.dongles[i].dongle_data, 0);
		assert_equal("cooldown", (int)data.dongles[i].dongle_cooldown, 0);
		assert_equal("fila vazia", data.dongles[i].queue.size, 0);
		assert_equal("capacidade", data.dongles[i].queue.capacity, 2);
		assert_equal("ticket", (int)data.dongles[i].next_ticket, 0);
		i++;
	}
	destroy_dongles(data.dongles, 3);
	free(data.dongles);
	return (0);
}
