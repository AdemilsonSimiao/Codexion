/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:47:27 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 19:05:10 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_done(t_coder *coder)
{
	int	count;
	int	required;

	required = coder->config->number_of_compiles_required;
	pthread_mutex_lock(&coder->data->state_mutex);
	count = coder->compile_count;
	pthread_mutex_unlock(&coder->data->state_mutex);
	return (count >= required);
}

int	is_burned_out(t_coder *coder)
{
	int		required;
	int		burnout;
	int		count;
	long	start;

	burnout = coder->config->time_to_burnout;
	required = coder->config->number_of_compiles_required;
	pthread_mutex_lock(&coder->data->state_mutex);
	count = coder->compile_count;
	start = coder->compile_start;
	pthread_mutex_unlock(&coder->data->state_mutex);
	if (count >= required)
		return (0);
	return (get_time_ms() - start >= burnout);
}

int	all_done(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.number_of_coders)
	{
		if (!is_done(&data->coders[i]))
			return (0);
		i++;
	}
	return (1);
}

int	find_burned_out(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.number_of_coders)
	{
		if (is_burned_out(&data->coders[i]))
			return (data->coders[i].id);
		i++;
	}
	return (0);
}

int	is_stopped(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->stop_mutex);
	stopped = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stopped);
}
