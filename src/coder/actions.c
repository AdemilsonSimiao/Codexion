/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:06:42 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 15:37:20 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	do_compile(t_coder *coder)
{
	log_state(coder->data, coder->id, "is compiling");
	pthread_mutex_lock(&coder->data->state_mutex);
	coder->compile_start = get_time_ms();
	pthread_mutex_unlock(&coder->data->state_mutex);
	smart_sleep(coder->config->time_to_compile);
	pthread_mutex_lock(&coder->data->state_mutex);
	coder->compile_count += 1;
	pthread_mutex_unlock(&coder->data->state_mutex);
}

void	do_debug(t_coder *coder)
{
	log_state(coder->data, coder->id, "is debugging");
	smart_sleep(coder->config->time_to_debug);
}

void	do_refactor(t_coder *coder)
{
	log_state(coder->data, coder->id, "is refactoring");
	smart_sleep(coder->config->time_to_refactor);
}
