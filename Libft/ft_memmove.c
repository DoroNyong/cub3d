/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:17 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 13:30:20 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	num;
	char	*dest_tmp;
	char	*src_tmp;

	dest_tmp = (char *)dest;
	src_tmp = (char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			dest_tmp[n - 1] = src_tmp[n - 1];
			n--;
		}
	}
	else
	{
		num = 0;
		while (num < n)
		{
			dest_tmp[num] = src_tmp[num];
			num++;
		}
	}
	return (dest);
}
