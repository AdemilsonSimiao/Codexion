/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_dongles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 08:11:02 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 08:16:19 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	int		i;

	data.config.number_of_coders = 3;
	assert_equal("retorno", init_dongles(&data), 1);
	assert_equal("dongles alocado", data.dongles != NULL, 1);
	i = 0;
	while (i < 3)
	{
		assert_equal("em uso", data.dongles[i].dongle_data, 0);
		assert_equal("cooldown", (int)data.dongles[i].dongle_cooldown, 0);
		pthread_mutex_destroy(&data.dongles[i].mutex);
		pthread_cond_destroy(&data.dongles[i].cond);
		i++;
	}
	free(data.dongles);
	return (0);
}