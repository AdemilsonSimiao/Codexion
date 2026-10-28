/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:30:55 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 10:31:00 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	char	*argv[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "fifo", NULL};

	assert_equal("retorno", init_data(&data, argv), 1);
	assert_equal("coders", data.config.number_of_coders, 5);
	assert_equal("stop", data.stop, 0);
	assert_equal("start_time", data.start_time > 0, 1);
	assert_equal("lock log", pthread_mutex_lock(&data.log_mutex), 0);
	pthread_mutex_unlock(&data.log_mutex);
	assert_equal("lock stop", pthread_mutex_lock(&data.stop_mutex), 0);
	pthread_mutex_unlock(&data.stop_mutex);
	pthread_mutex_destroy(&data.log_mutex);
	pthread_mutex_destroy(&data.stop_mutex);
	return (0);
}
