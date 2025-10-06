/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:21:15 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 13:51:26 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			index;

	tmp = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (tmp[index] == (unsigned char)c)
			return (tmp + index);
		index++;
	}
	return (NULL);
}
