/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:01:46 by hjang             #+#    #+#             */
/*   Updated: 2024/10/16 14:48:25 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*tmp;
	unsigned char	uc;
	int				index;

	tmp = (unsigned char *)s;
	uc = (unsigned char)c;
	index = 0;
	while (s[index++] != '\0')
		tmp++;
	if (uc == '\0')
		return ((char *)tmp);
	while ((unsigned char *)s != tmp)
	{
		if (*(tmp) == uc)
			break ;
		tmp--;
	}
	if ((*tmp) == uc)
		return ((char *)tmp);
	else
		return (NULL);
}
