/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:05:59 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 19:06:04 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	char	*argv[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "fifo", NULL};

	init_data(&data, argv);
	assert_equal("antes do stop", is_stopped(&data), 0);
	log_state(&data, 1, "aparece");
	data.stop = 1;
	assert_equal("depois do stop", is_stopped(&data), 1);
	log_state(&data, 1, "NAO deve aparecer");
	cleanup_all(&data);
	return (0);
}
