/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setting_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:19 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 16:46:20 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**add_texture_path(char **texture_paths, int count, char *new_path)
{
	char	**new_paths;
	int		i;

	new_paths = (char **)malloc(sizeof(char *) * (count + 2));
	if (!new_paths)
	{
		free(new_path);
		printf("Error\n%s\n", "Failed to allocate memory for texture paths.");
		exit(1);
	}
	i = 0;
	while (i < count)
	{
		new_paths[i] = texture_paths[i];
		i++;
	}
	if (texture_paths)
		free(texture_paths);
	new_paths[count] = new_path;
	new_paths[count + 1] = NULL;
	return (new_paths);
}

static void	parse_texture(char ***texture_paths, int *count, char *line)
{
	char	*trimmed_path;

	trimmed_path = ft_strtrim(line, " \t");
	if (!trimmed_path)
	{
		printf("Error\n%s\n", "Failed to allocate memory for texture path.");
		exit(1);
	}
	*texture_paths = add_texture_path(*texture_paths, *count, trimmed_path);
	(*count)++;
}

void	parsing_texture(t_sl *sl, char **lines)
{
	int		i;
	char	*line;

	i = 0;
	while (lines[i])
	{
		line = skip_whitespace(lines[i]);
		if (ft_strncmp(line, "NO ", 3) == 0)
			parse_texture(&sl->config.no_path, &sl->config.no_count, line + 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_texture(&sl->config.so_path, &sl->config.so_count, line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_texture(&sl->config.we_path, &sl->config.we_count, line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_texture(&sl->config.ea_path, &sl->config.ea_count, line + 3);
		i++;
	}
}
