/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:01:03 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 13:52:37 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*tmp;
	unsigned char	uc;

	tmp = (unsigned char *)s;
	uc = (unsigned char)c;
	while (*(tmp) != '\0')
	{
		if (*(tmp) == uc)
			break ;
		tmp++;
	}
	if (*(tmp) == '\0' && uc != '\0')
		return (NULL);
	else
		return ((char *)tmp);
}
