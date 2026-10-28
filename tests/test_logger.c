/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_logger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:33:52 by pc2               #+#    #+#             */
/*   Updated: 2026/10/27 21:33:56 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;

	pthread_mutex_init(&data.log_mutex, NULL);
	data.start_time = get_time_ms();
	smart_sleep(50);
	log_state(&data, 1, "has taken a dongle");
	smart_sleep(200);
	log_state(&data, 1, "is compiling");
	pthread_mutex_destroy(&data.log_mutex);
	return (0);
}