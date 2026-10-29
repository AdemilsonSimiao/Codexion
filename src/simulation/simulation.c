/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:06:30 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 09:24:00 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	simulation(t_data *data)
{
	int	i;
	int	coders_number;

	coders_number = data->config.number_of_coders;
	i = 0;
	while (i < coders_number)
	{
		pthread_create(&data->coders[i].thread,
			NULL, coder_routine, &data->coders[i]);
		i++;
	}
	i = 0;
	while (i < coders_number)
	{
		pthread_join(data->coders[i].thread, NULL);
		i++;
	}
}
