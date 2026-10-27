/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_number_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:37:47 by pc2               #+#    #+#             */
/*   Updated: 2026/10/26 21:26:16 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	assert_equal("123", number_validation("123"), 1);
	assert_equal("0", number_validation("0"), 1);
	assert_equal("a1", number_validation("a1"), 0);
	assert_equal("1a", number_validation("1a"), 0);
	assert_equal("-5", number_validation("-5"), 0);
	assert_equal("3.5", number_validation("3.5"), 0);
	assert_equal("", number_validation(""), 0);
	return (0);
}
