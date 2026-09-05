/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:35:32 by hjang             #+#    #+#             */
/*   Updated: 2024/10/25 15:12:38 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, char const *set)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(set);
	while (index < len)
	{
		if (set[index++] == c)
			return (1);
	}
	return (0);
}

static int	res_begin_index(char const *s1, char const *set)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (!check_char(s1[index], set))
			break ;
		index++;
	}
	return (index);
}

static int	res_end_index(char const *s1, char const *set)
{
	int	index;

	index = (int)ft_strlen(s1) - 1;
	while (index != 0)
	{
		if (!check_char(s1[index], set))
			break ;
		index--;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		res_len;
	int		index;
	int		index_res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	res_len = res_end_index(s1, set) - res_begin_index(s1, set) + 1;
	if (res_len <= 0)
		return (ft_strdup(""));
	else
		res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	index = res_begin_index(s1, set);
	index_res = 0;
	while (index <= res_end_index(s1, set))
		res[index_res++] = s1[index++];
	res[index_res] = '\0';
	return (res);
}
