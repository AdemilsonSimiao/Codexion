/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_coders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:02:07 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 10:02:21 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	int		i;

	data.config.number_of_coders = 3;
	data.config.dongle_cooldown = 100;
	init_dongles(&data);
	assert_equal("retorno", init_coders(&data), 1);
	i = 0;
	while (i < 3)
	{
		assert_equal("id", data.coders[i].id, i + 1);
		assert_equal("compiles", data.coders[i].compile_count, 0);
		assert_equal("left", data.coders[i].left_dongle == &data.dongles[i], 1);
		assert_equal("right", data.coders[i].right_dongle == &data.dongles[(i + 1) % 3], 1);
		assert_equal("config", data.coders[i].config == &data.config, 1);
		pthread_mutex_destroy(&data.dongles[i].mutex);
		pthread_cond_destroy(&data.dongles[i].cond);
		i++;
	}
	free(data.coders);
	free(data.dongles);
	return (0);
}
