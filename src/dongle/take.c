/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:51:42 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 16:51:54 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	wait_and_take(t_coder *coder, t_dongle *first, t_dongle *second)
{
	int	taken;

	taken = 0;
	while (!taken && !is_stopped(coder->data))
	{
		if (!blocked_by_neighbor(coder, first)
			&& !blocked_by_neighbor(coder, second))
		{
			lock_pair(first, second);
			taken = try_take(coder, first, second);
			unlock_pair(first, second);
		}
		if (!taken)
			usleep(200);
	}
	return (taken);
}

static int	lone_coder(t_coder *coder)
{
	log_state(coder->data, coder->id, "has taken a dongle");
	while (!is_stopped(coder->data))
		usleep(200);
	return (0);
}

int	take_dongles(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;
	long		deadline;

	first = coder->left_dongle;
	second = coder->right_dongle;
	if (first == second)
		return (lone_coder(coder));
	if (first > second)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	deadline = deadline_of(coder);
	request_dongle(coder, first, deadline);
	request_dongle(coder, second, deadline);
	if (!wait_and_take(coder, first, second))
		return (0);
	log_state(coder->data, coder->id, "has taken a dongle");
	log_state(coder->data, coder->id, "has taken a dongle");
	return (1);
}
