/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:06:39 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 19:35:23 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = arg;
	while (!is_stopped(coder->data) && !is_burned_out(coder))
	{
		take_dongles(coder);
		do_compile(coder);
		drop_dongles(coder);
		do_debug(coder);
		do_refactor(coder);
	}
	return (NULL);
}
