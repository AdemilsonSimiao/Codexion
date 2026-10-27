/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:27:04 by pc2               #+#    #+#             */
/*   Updated: 2026/10/27 08:27:13 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_config	config;
	char		*argv[] = {"./codexion", "5", "800", "200", "210", "220", "3", "100", "fifo", NULL};

	fill_config(&config, argv);
	assert_equal("number_of_coders", config.number_of_coders, 5);
	assert_equal("time_to_burnout", config.time_to_burnout, 800);
	assert_equal("time_to_compile", config.time_to_compile, 200);
	assert_equal("time_to_debug", config.time_to_debug, 210);
	assert_equal("time_to_refactor", config.time_to_refactor, 220);
	assert_equal("compiles_required", config.number_of_compiles_required, 3);
	assert_equal("dongle_cooldown", config.dongle_cooldown, 100);
	assert_equal("scheduler", strcmp(config.scheduler, "fifo"), 0);
	return (0);
}
