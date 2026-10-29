/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:47:32 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 18:42:36 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		id;

	data = arg;
	while (1)
	{
		id = find_burned_out(data);
		if (id != 0)
		{
			log_state(data, id, "burned out");
			set_stop(data);
			break ;
		}
		if (all_done(data))
		{
			set_stop(data);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
