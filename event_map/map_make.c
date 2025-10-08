/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:27:44 by hjang             #+#    #+#             */
/*   Updated: 2025/10/08 13:35:37 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	map_make_1(t_sl *sl)
{
	sl->map = (char **)malloc(sizeof(char *) * (sl->mapinfo.x + 1));
	if (!sl->map)
		return (0);
	sl->map[sl->mapinfo.x] = NULL;
	return (1);
}

static int	map_make_2(t_sl *sl)
{
	int	index;

	index = 0;
	while (index < sl->mapinfo.x)
	{
		sl->map[index] = (char *)malloc(sizeof(char) * (sl->mapinfo.y + 1));
		if (!sl->map[index])
		{
			free_map(sl, index);
			return (0);
		}
		sl->map[index][sl->mapinfo.y] = '\0';
		index++;
	}
	return (1);
}

int	map_make(t_sl *sl, char *map_str)
{
	if (!map_make_1(sl))
		return (0);
	if (!map_make_2(sl))
		return (0);
	map_per_init(sl, map_str);
	if (!map_wall_check(sl))
	{
		free_map(sl, sl->mapinfo.x);
		return (0);
	}
	return (1);
}
