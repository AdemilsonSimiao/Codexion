/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:38:20 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 16:11:23 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codexion.h>

int	init_data(t_data *data, char **argv)
{
	fill_config(&data->config, argv);
	if (pthread_mutex_init(&data->log_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->log_mutex);
		return (0);
	}
	data->start_time = get_time_ms();
	data->stop = 0;
	return (1);
}
