/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:44:46 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 16:39:37 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			index;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	index = 0;
	while (us1[index] && us2[index] && index < n)
	{
		if (us1[index] != us2[index])
			return (us1[index] - us2[index]);
		index++;
	}
	if (index < n)
		return (us1[index] - us2[index]);
	return (0);
}
