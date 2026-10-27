/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:43:29 by pc2               #+#    #+#             */
/*   Updated: 2026/10/27 08:58:59 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_config	config;

	if (args_validation(argc, argv) == 0)
	{
		fprintf(stderr, "Invalid mode. "
			"Use ./codexion 5 800 200 200 200 3 100 fifo\n");
		return (1);
	}
	fill_config(&config, argv);
	return (0);
}
