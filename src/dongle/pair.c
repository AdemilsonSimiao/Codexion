/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:53:23 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 16:53:28 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_free(t_dongle *dongle)
{
	return (dongle->dongle_data == 0
		&& get_time_ms() >= dongle->dongle_cooldown);
}

void	lock_pair(t_dongle *first, t_dongle *second)
{
	pthread_mutex_lock(&first->mutex);
	pthread_mutex_lock(&second->mutex);
}

void	unlock_pair(t_dongle *first, t_dongle *second)
{
	pthread_mutex_unlock(&second->mutex);
	pthread_mutex_unlock(&first->mutex);
}

int	try_take(t_coder *coder, t_dongle *first, t_dongle *second)
{
	if (!is_free(first) || !is_free(second))
		return (0);
	heap_remove(&first->queue, coder->id);
	heap_remove(&second->queue, coder->id);
	first->dongle_data = 1;
	second->dongle_data = 1;
	return (1);
}
