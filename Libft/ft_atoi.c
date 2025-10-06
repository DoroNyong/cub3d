/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:58 by hjang             #+#    #+#             */
/*   Updated: 2024/10/25 15:14:12 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	minus;

	index = 0;
	result = 0;
	minus = 1;
	while (nptr[index] == ' ' || nptr[index] == '\n' \
			|| nptr[index] == '\t' || nptr[index] == '\v' \
			|| nptr[index] == '\f' || nptr[index] == '\r')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			minus = -minus;
		index++;
	}
	while (ft_isdigit(nptr[index]))
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (result * minus);
}
