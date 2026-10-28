/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:41:50 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 16:48:07 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	cleanup_all(t_data *data)
{
	if (data->dongles != NULL)
		destroy_dongles(data->dongles,
			data->config.number_of_coders);
	free(data->dongles);
	free(data->coders);
	destroy_shared(data);
}
