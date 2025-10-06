/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:00:54 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 13:51:39 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;
	size_t			index;

	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (s1_tmp[index] != s2_tmp[index])
			return (s1_tmp[index] - s2_tmp[index]);
		index++;
	}
	return (0);
}
