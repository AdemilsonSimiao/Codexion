/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:40:51 by pc2               #+#    #+#             */
/*   Updated: 2026/10/29 11:42:21 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_data	data;
	char	*argv[] = {"./codexion", "2", "800", "200", "200", "200", "3", "100", "fifo", NULL};

	assert_equal("retorno", init_data(&data, argv), 1);
	simulation(&data);
	cleanup_all(&data);
	return (0);
}
