/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:58:17 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 23:12:54 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	number_validation(char *str)
{
	int	i;

	if (*str == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	fifo_edf_validation(char *str)
{
	if (strcmp(str, "fifo") == 0 || strcmp(str, "edf") == 0)
		return (1);
	return (0);
}

int	args_validation(int argc, char **argv)
{
	int	i;

	if (argc != 9)
		return (0);
	i = 1;
	while (i <= 7)
	{
		if (number_validation(argv[i]) == 0)
			return (0);
		i++;
	}
	if (limits_validation(argv) == 0)
		return (0);
	if (fifo_edf_validation(argv[8]) == 0)
		return (0);
	if (fifo_edf_validation(argv[8]) == 0)
		return (0);
	return (1);
}
