/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:52:49 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 16:52:54 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long	deadline_of(t_coder *coder)
{
	long	deadline;

	pthread_mutex_lock(&coder->data->state_mutex);
	deadline = coder->compile_start
		+ coder->config->time_to_burnout;
	pthread_mutex_unlock(&coder->data->state_mutex);
	return (deadline);
}

void	request_dongle(t_coder *coder, t_dongle *dongle, long deadline)
{
	t_request	request;

	request.coder_id = coder->id;
	pthread_mutex_lock(&dongle->mutex);
	if (strcmp(coder->config->scheduler, "edf") == 0)
		request.key = deadline;
	else
		request.key = dongle->next_ticket++;
	heap_push(&dongle->queue, request);
	pthread_mutex_unlock(&dongle->mutex);
}

static int	head_id(t_dongle *dongle)
{
	t_request	*head;
	int			id;

	pthread_mutex_lock(&dongle->mutex);
	head = heap_peek(&dongle->queue);
	id = 0;
	if (head != NULL)
		id = head->coder_id;
	pthread_mutex_unlock(&dongle->mutex);
	return (id);
}

int	dongle_ready(t_dongle *dongle)
{
	int	ready;

	pthread_mutex_lock(&dongle->mutex);
	ready = is_free(dongle);
	pthread_mutex_unlock(&dongle->mutex);
	return (ready);
}

int	blocked_by_neighbor(t_coder *coder, t_dongle *dongle)
{
	int		id;
	t_coder	*other;

	id = head_id(dongle);
	if (id == 0 || id == coder->id)
		return (0);
	other = &coder->data->coders[id - 1];
	return (dongle_ready(other->left_dongle)
		&& dongle_ready(other->right_dongle));
}
