/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:43:14 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 18:43:23 by pc2              ###   ########.fr       */
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
	data.coders[2].compile_start = now - 900;
	monitor_routine(&data);
	assert_equal("stop apos burnout", data.stop, 1);
	data.stop = 0;
	i = 0;
	while (i < 5)
		data.coders[i++].compile_count = 3;
	monitor_routine(&data);
	assert_equal("stop apos todos terminarem", data.stop, 1);
	cleanup_all(&data);
	return (0);
}
