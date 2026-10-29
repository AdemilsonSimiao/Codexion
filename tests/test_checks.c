/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:17:25 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 18:17:34 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	char	*argv[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "fifo", NULL};
	long	now;
	int		i;

	init_data(&data, argv);
	now = get_time_ms();
	i = 0;
	while (i < 5)
		data.coders[i++].compile_start = now;
	assert_equal("ninguem queimou", find_burned_out(&data), 0);
	assert_equal("ninguem terminou", all_done(&data), 0);
	data.coders[1].compile_start = now - 900;
	assert_equal("coder 2 queimou", find_burned_out(&data), 2);
	data.coders[1].compile_count = 3;
	assert_equal("quem terminou nao queima", find_burned_out(&data), 0);
	i = 0;
	while (i < 5)
		data.coders[i++].compile_count = 3;
	assert_equal("todos terminaram", all_done(&data), 1);
	cleanup_all(&data);
	return (0);
}
