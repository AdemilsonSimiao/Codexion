/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:06:30 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 19:27:20 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	init_times(t_data *data)
{
	int	i;
	
	data->start_time = get_time_ms();
	i = 0;
	while (i < data->config.number_of_coders)
	{
		data->coders[i].compile_start = data->start_time;
		i++;
	}
}

void	simulation(t_data *data)
{
	int	i;
	int	coders_number;

	init_times(data);
	coders_number = data->config.number_of_coders;
	pthread_create(&data->monitor, NULL, monitor_routine, data);
	i = 0;
	while (i < coders_number)
	{
		pthread_create(&data->coders[i].thread,
			NULL, coder_routine, &data->coders[i]);
		i++;
	}
	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < coders_number)
	{
		pthread_join(data->coders[i].thread, NULL);
		i++;
	}
}
