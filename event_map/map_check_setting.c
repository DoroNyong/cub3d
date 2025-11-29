/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:12 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/29 13:58:08 by byeolee          ###   ########.fr       */
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
	exit(1);
}

static void	checking_parsing(t_sl *sl, char **lines)
{
	if (sl->config.no_count == 0)
		handle_error(sl, lines, "no_path is missing.");
	if (sl->config.so_count == 0)
		handle_error(sl, lines, "so_path is missing.");
	if (sl->config.we_count == 0)
		handle_error(sl, lines, "we_path is missing.");
	if (sl->config.ea_count == 0)
		handle_error(sl, lines, "ea_path is missing.");
	if (sl->config.f_count != 1)
		handle_error(sl, lines, "Enter floor color less or more than one.");
	if (sl->config.c_count != 1)
		handle_error(sl, lines, "Enter ceiling color less or more than one.");
	if (sl->config.f_color == -1)
		handle_error(sl, lines, "f_color is missing.");
	if (sl->config.c_color == -1)
		handle_error(sl, lines, "c_color is missing.");
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
		if (parsing_texture(sl, line) || parsing_colors(sl, line))
			i++;
		else
			return (check_setting(sl, lines, i));
	}
	checking_parsing(sl, lines);
	return (i);
}
