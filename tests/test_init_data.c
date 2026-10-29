/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:30:55 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 15:38:24 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	char	*argv[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "fifo", NULL};

	assert_equal("retorno", init_data(&data, argv), 1);
	assert_equal("dongles", data.dongles != NULL, 1);
	assert_equal("coders", data.coders != NULL, 1);
	assert_equal("lock state", pthread_mutex_lock(&data.state_mutex), 0);
	pthread_mutex_unlock(&data.state_mutex);
	destroy_dongles(data.dongles, 5);
	free(data.dongles);
	free(data.coders);
	destroy_shared(&data);
	return (0);
}
