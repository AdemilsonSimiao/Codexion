/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:38:04 by pc2               #+#    #+#             */
/*   Updated: 2026/10/26 20:41:46 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	assert_equal(char *input, int expected)
{
	int	result;

	result = number_validation(input);
	if (result == expected)
		printf("OK  \"%s\" -> %d\n", input, result);
	else
		printf("KO  \"%s\" -> %d (esperado %d)\n", input, result, expected);
}
