/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:45:54 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/07 15:38:30 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && \
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && \
			line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

static char	*concatenate_map_lines(char **lines)
{
	char	*map_only_str;
	char	*temp;
	int		i;

	map_only_str = ft_strdup("");
	if (!map_only_str)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
		{
			temp = map_only_str;
			map_only_str = ft_strjoin(temp, lines[i]);
			free(temp);
			temp = map_only_str;
			map_only_str = ft_strjoin(temp, "\n");
			free(temp);
		}
		free(lines[i]);
		i++;
	}
	free(lines);
	return (map_only_str);
}

static void	create_map(t_sl *sl, char *map_only_str)
{
	if (!map_str_check(sl, map_only_str))
	{
		free_texture_paths(sl);
		free(map_only_str);
		exit(1);
	}
	if (!map_make(sl, map_only_str))
	{
		free_texture_paths(sl);
		free(map_only_str);
		exit(1);
	}
	free(map_only_str);
}

void	process_map_lines(t_sl *sl, char **lines)
{
	char	*map_only_str;

	map_only_str = concatenate_map_lines(lines);
	create_map(sl, map_only_str);
}
