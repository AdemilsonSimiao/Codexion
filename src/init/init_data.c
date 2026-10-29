/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:38:20 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 15:40:20 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	init_shared(t_data *data)
{
	if (pthread_mutex_init(&data->log_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->log_mutex);
		return (0);
	}
	if (pthread_mutex_init(&data->state_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->stop_mutex);
		pthread_mutex_destroy(&data->log_mutex);
		return (0);
	}
	
	data->start_time = get_time_ms();
	data->stop = 0;
	return (1);
}

void	destroy_shared(t_data *data)
{
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->stop_mutex);
	pthread_mutex_destroy(&data->state_mutex);
}

int	init_data(t_data *data, char **argv)
{
	fill_config(&data->config, argv);
	if (init_shared(data) == 0)
		return (0);
	if (init_dongles(data) == 0)
	{
		destroy_shared(data);
		return (0);
	}
	if (init_coders(data) == 0)
	{
		destroy_dongles(data->dongles,
			data->config.number_of_coders);
		free(data->dongles);
		data->dongles = NULL;
		destroy_shared(data);
		return (0);
	}
	return (1);
}
