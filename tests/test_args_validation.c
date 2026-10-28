/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_args_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:08:34 by pc2               #+#    #+#             */
/*   Updated: 2026/10/27 21:11:59 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	char	*ok_fifo[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "fifo", NULL};
	char	*ok_edf[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "edf", NULL};
	char	*missing[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", NULL};
	char	*negative[] = {"./codexion", "5", "-800", "200", "200", "200", "3", "100", "fifo", NULL};
	char	*not_num[] = {"./codexion", "5", "800", "abc", "200", "200", "3", "100", "fifo", NULL};
	char	*bad_sched[] = {"./codexion", "5", "800", "200", "200", "200", "3", "100", "xyz", NULL};
	char	*last_num[] = {"./codexion", "5", "800", "200", "200", "200", "3", "abc", "fifo", NULL};

	assert_equal("fifo valido", args_validation(9, ok_fifo), 1);
	assert_equal("edf valido", args_validation(9, ok_edf), 1);
	assert_equal("falta scheduler", args_validation(8, missing), 0);
	assert_equal("negativo", args_validation(9, negative), 0);
	assert_equal("abc no 3o", args_validation(9, not_num), 0);
	assert_equal("scheduler xyz", args_validation(9, bad_sched), 0);
	assert_equal("abc no ultimo numero", args_validation(9, last_num), 0);
	return (0);
}
