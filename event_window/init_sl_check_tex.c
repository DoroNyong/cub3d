/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sl_check_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:11:58 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/07 15:54:08 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_texture_file(char *path)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error\nTexture file must have .xpm extension: %s\n", path);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open texture file: %s\n", path);
		return (0);
	}
	close(fd);
	return (1);
}

static int	check_texdir(char **paths, int count)
{
	int	i;

	if (count == 0)
		return (1);
	i = 0;
	while (i < count)
	{
		if (!check_texture_file(paths[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_tex(t_sl *sl)
{
	if (!check_texdir(sl->config.no_path, sl->config.no_count) || \
		!check_texdir(sl->config.so_path, sl->config.so_count) || \
		!check_texdir(sl->config.we_path, sl->config.we_count) || \
		!check_texdir(sl->config.ea_path, sl->config.ea_count))
	{
		free_texture_paths(sl);
		if (sl->map)
			free_map(sl, sl->mapinfo.x);
		exit(1);
	}
}
