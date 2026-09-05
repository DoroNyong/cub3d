/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:04:13 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 14:43:01 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n, int count)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n >= 10)
		count = count_len(n / 10, count);
	count++;
	return (count);
}

static char	*put_digit(char *res, int n, int len, int index)
{
	if (n == -2147483648)
	{
		ft_strlcpy(res, "-2147483648", 12);
		return (res);
	}
	else if (n < 0)
	{
		res[index] = '-';
		n = -n;
		index++;
	}
	if (n >= 10)
		res = put_digit(res, n / 10, len, index + 1);
	if (res[0] == '-')
		res[(len - index)] = (n % 10) + '0';
	else
		res[(len - index - 1)] = (n % 10) + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = count_len(n, 0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	put_digit(res, n, len, 0);
	res[len] = '\0';
	return (res);
}
