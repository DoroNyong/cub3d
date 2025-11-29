/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:41:07 by hjang             #+#    #+#             */
/*   Updated: 2025/11/29 13:34:18 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_sl *sl, int index)
{
	int	i;

	i = 0;
	while (i < index)
		free(sl->map[i++]);
	free(sl->map);
}

void	free_texture_paths(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->config.no_count)
		free(sl->config.no_path[i++]);
	if (sl->config.no_path)
		free(sl->config.no_path);
	i = 0;
	while (i < sl->config.so_count)
		free(sl->config.so_path[i++]);
	if (sl->config.so_path)
		free(sl->config.so_path);
	i = 0;
	while (i < sl->config.we_count)
		free(sl->config.we_path[i++]);
	if (sl->config.we_path)
		free(sl->config.we_path);
	i = 0;
	while (i < sl->config.ea_count)
		free(sl->config.ea_path[i++]);
	if (sl->config.ea_path)
		free(sl->config.ea_path);
}

char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}
