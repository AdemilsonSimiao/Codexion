/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:02:52 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 15:51:40 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static long	deadline_of(t_coder *coder)
{
	long	deadline;

	pthread_mutex_lock(&coder->data->state_mutex);
	deadline = coder->compile_start
		+ coder->config->time_to_burnout;
	pthread_mutex_unlock(&coder->data->state_mutex);
	return (deadline);
}

static int	enqueue(t_coder *coder, t_dongle *dongle, long deadline)
{
	t_request	request;

	request.coder_id = coder->id;
	if (strcmp(coder->config->scheduler, "edf") == 0)
		request.key = deadline;
	else
		request.key = dongle->next_ticket++;
	return (heap_push(&dongle->queue, request));
}

static int	is_my_turn(t_coder *coder, t_dongle *dongle)
{
	t_request	*first;

	first = heap_peek(&dongle->queue);
	return (first != NULL
		&& first->coder_id == coder->id
		&& dongle->dongle_data == 0
		&& get_time_ms() >= dongle->dongle_cooldown);
}

void	take_dongle(t_coder *coder, t_dongle *dongle)
{
	long		deadline;
	t_request	request;

	deadline = deadline_of(coder);
	pthread_mutex_lock(&dongle->mutex);
	enqueue(coder, dongle, deadline);
	while (!is_stopped(coder->data) && !is_my_turn(coder, dongle))
	{
		pthread_mutex_unlock(&dongle->mutex);
		usleep(200);
		pthread_mutex_lock(&dongle->mutex);
	}
	if (!is_stopped(coder->data) && is_my_turn(coder, dongle))
	{
		heap_pop(&dongle->queue, &request);
		dongle->dongle_data = 1;
	}
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
