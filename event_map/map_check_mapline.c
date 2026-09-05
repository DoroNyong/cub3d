/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_mapline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:50:54 by byeolee           #+#    #+#             */
/*   Updated: 2025/12/15 15:05:04 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_newlines_between(char *start, char *end)
{
	int	nl_count;

	nl_count = 0;
	while (start < end)
	{
		if (*start == '\n')
			nl_count++;
		start++;
	}
	return (nl_count);
}

static int	check_map_newlines(char *full_file, char **lines, int map_start_idx)
{
	char	*ptr;
	char	*found;
	int		i;
	int		nl_count;

	ptr = full_file;
	i = 0;
	while (lines[i])
	{
		found = ft_strnstr(ptr, lines[i], ft_strlen(ptr));
		if (!found)
			return (0);
		if (i > map_start_idx)
		{
			nl_count = count_newlines_between(ptr, found);
			if (nl_count > 1)
				return (0);
		}
		ptr = found + ft_strlen(lines[i]);
		i++;
	}
	return (1);
}

void	map_empty_line_check(t_sl *sl, char *full_file, char **lines, \
								int map_start_idx)
{
	if (!check_map_newlines(full_file, lines, map_start_idx))
		handle_error(sl, lines, "Map is separated by empty lines");
}
