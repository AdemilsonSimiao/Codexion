/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:38:24 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 16:11:38 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	init_one_dongle(t_dongle *dongle)
{
	if (pthread_mutex_init(&dongle->mutex, NULL) != 0)
		return (0);
	if (pthread_cond_init(&dongle->cond, NULL) != 0)
	{
		pthread_mutex_destroy(&dongle->mutex);
		return (0);
	}
	dongle->dongle_data = 0;
	dongle->dongle_cooldown = 0;
	return (1);
}

void	destroy_dongles(t_dongle *dongles, int count)
{
	while (count > 0)
	{
		count--;
		pthread_cond_destroy(&dongles[count].cond);
		pthread_mutex_destroy(&dongles[count].mutex);
	}
}

int	init_dongles(t_data *data)
{
	int	i;
	int	count_coders;

	count_coders = data->config.number_of_coders;
	data->dongles = malloc(sizeof(*data->dongles) * count_coders);
	if (data->dongles == NULL)
		return (0);
	i = 0;
	while (i < count_coders)
	{
		if (!init_one_dongle(&data->dongles[i]))
		{
			destroy_dongles(data->dongles, i);
			free(data->dongles);
			data->dongles = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}
