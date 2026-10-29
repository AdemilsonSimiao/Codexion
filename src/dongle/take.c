/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:02:52 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 19:00:20 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	take_dongle(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	while (!is_stopped(coder->data)
		&& (dongle->dongle_data != 0
			|| get_time_ms() < dongle->dongle_cooldown))
	{
		pthread_mutex_unlock(&dongle->mutex);
		usleep(200);
		pthread_mutex_lock(&dongle->mutex);
	}
	dongle->dongle_data = 1;
	pthread_mutex_unlock(&dongle->mutex);
	log_state(coder->data, coder->id, "has taken a dongle");
}

void	take_dongles(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;

	if (coder->left_dongle < coder->right_dongle)
	{
		first = coder->left_dongle;
		second = coder->right_dongle;
	}
	else
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	take_dongle(coder, first);
	take_dongle(coder, second);
}
