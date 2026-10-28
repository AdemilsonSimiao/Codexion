/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:05:05 by pc2               #+#    #+#             */
/*   Updated: 2026/10/27 21:36:29 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	log_state(t_data *data, int id, const char *msg)
{
	long	time_line;

	pthread_mutex_lock(&data->log_mutex);
	time_line = get_time_ms() - data->start_time;
	printf("%ld %i %s\n", time_line, id, msg);
	pthread_mutex_unlock(&data->log_mutex);
}
