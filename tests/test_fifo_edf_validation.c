/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fifo_edf_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:27:47 by pc2               #+#    #+#             */
/*   Updated: 2026/10/26 21:31:33 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	assert_equal("fifo", fifo_edf_validation("fifo"), 1);
	assert_equal("edf", fifo_edf_validation("edf"), 1);
	assert_equal("FIFO", fifo_edf_validation("FIFO"), 0);
	assert_equal("fifo ", fifo_edf_validation("fifo "), 0);
	assert_equal("abc", fifo_edf_validation("abc"), 0);
	assert_equal("", fifo_edf_validation(""), 0);
	return (0);
}
