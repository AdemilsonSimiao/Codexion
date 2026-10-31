/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:33:33 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 21:33:38 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	fits_int(char *str)
{
	size_t	len;

	while (*str == '0' && str[1] != '\0')
		str++;
	len = strlen(str);
	if (len > 10)
		return (0);
	if (len == 10 && strcmp(str, "2147483647") > 0)
		return (0);
	return (1);
}

int	limits_validation(char **argv)
{
	int	i;

	i = 1;
	while (i <= 7)
	{
		if (fits_int(argv[i]) == 0)
			return (0);
		i++;
	}
	if (atoi(argv[1]) < 1 || atoi(argv[6]) < 1)
		return (0);
	return (1);
}
