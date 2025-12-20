/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:12 by byeolee           #+#    #+#             */
/*   Updated: 2025/12/20 15:38:03 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	handle_error(t_sl *sl, char **lines, const char *message)
{
	printf("Error\n%s\n", message);
	free_texture_paths(sl);
	if (lines)
		free_lines(lines);
	if (sl->map)
		free_map(sl, sl->mapinfo.y);
	if (sl->full_file)
	{
		free(sl->full_file);
		sl->full_file = NULL;
	}
	exit(1);
}

int	parse_config_lines(t_sl *sl, char **lines)
{
	int		i;
	char	*line;

	i = 0;
	while (lines[i])
	{
		line = skip_whitespace(lines[i]);
		if (*line == '\0')
		{
			i++;
			continue ;
		}
		if (parsing_texture(sl, line) || parsing_colors(sl, line, lines))
			i++;
		else if (*line == '1')
			return (check_setting(sl, lines, i));
		else
		{
			checking_parsing(sl, lines);
			handle_error(sl, lines, "Invalid line in configuration file");
		}
	}
	checking_parsing(sl, lines);
	return (i);
}
