/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:06:42 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 10:59:22 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	do_compile(t_coder *coder)
{
	log_state(coder->data, coder->id, "is compiling");
	coder->compile_start = get_time_ms();
	smart_sleep(coder->config->time_to_compile);
	coder->compile_count += 1;
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
