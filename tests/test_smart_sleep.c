/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_smat_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:51:02 by pc2               #+#    #+#             */
/*   Updated: 2026/10/27 18:51:16 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	long	start;
	long	end;

	start = get_time_ms();
	smart_sleep(200);
	end = get_time_ms();
	printf("diferenca: %ld ms\n", end - start);
	return (0);
}
