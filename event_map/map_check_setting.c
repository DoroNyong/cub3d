/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:12 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 16:46:13 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

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

static void	handle_error(t_sl *sl, char **lines, const char *message)
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
	if (sl->config.f_color == -1)
		handle_error(sl, lines, "f_color is missing.");
	if (sl->config.c_color == -1)
		handle_error(sl, lines, "c_color is missing.");
}

void	parse_config_lines(t_sl *sl, char **lines)
{
	parsing_texture(sl, lines);
	parsing_colors(sl, lines);
	checking_parsing(sl, lines);
}
