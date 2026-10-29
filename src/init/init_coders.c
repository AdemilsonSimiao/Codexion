/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:38:18 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 08:54:48 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_coders(t_data *data)
{
	int	i;
	int	count;

	count = data->config.number_of_coders;
	data->coders = malloc(sizeof(*data->coders) * count);
	if (data->coders == NULL)
		return (0);
	i = 0;
	while (i < count)
	{
		data->coders[i].id = i + 1;
		data->coders[i].compile_count = 0;
		data->coders[i].compile_start = 0;
		data->coders[i].left_dongle = &data->dongles[i];
		data->coders[i].right_dongle = &data->dongles[(i + 1) % count];
		data->coders[i].config = &data->config;
		data->coders[i].data = data;
		i++;
	}
	return (1);
}
