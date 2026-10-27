/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:38:04 by pc2               #+#    #+#             */
/*   Updated: 2026/10/26 21:31:50 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	assert_equal(char *label, int result, int expected)
{
	if (result == expected)
		printf("OK  \"%s\" -> %d\n", label, result);
	else
		printf("KO  \"%s\" -> %d (esperado %d)\n", label, result, expected);
}
