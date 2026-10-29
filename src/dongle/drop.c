/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:03:55 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 11:24:45 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	drop_dongle(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->dongle_data = 0;
	dongle->dongle_cooldown = get_time_ms() + coder->config->dongle_cooldown;
	pthread_mutex_unlock(&dongle->mutex);
}

void	drop_dongles(t_coder *coder)
{
	drop_dongle(coder, coder->left_dongle);
	drop_dongle(coder, coder->right_dongle);
}
