/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:15:26 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 13:20:21 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	num;
	char	*dest_tmp;
	char	*src_tmp;

	num = 0;
	dest_tmp = (char *)dest;
	src_tmp = (char *)src;
	while (num < n)
	{
		dest_tmp[num] = src_tmp[num];
		num++;
	}
	return (dest);
}
