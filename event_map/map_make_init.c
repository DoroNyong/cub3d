/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:22 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 16:46:33 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	map_end(t_sl *sl, char c, int x, int y)
{
	int	i;

	i = 0;
	if (c == '\n' || c == '\0')
	{
		while (x + i < sl->mapinfo.x)
		{
			sl->map[x + i][y] = ' ';
			i++;
		}
	}
	return (i);
}

static void	map_empty(t_sl *sl, char c, int x, int y)
{
	if (c == ' ')
		sl->map[x][y] = ' ';
}

static void	map_word(t_sl *sl, char c, int x, int y)
{
	if (c == 'W' || c == 'E' || c == 'S' || c == 'N' || c == '0' || c == '1')
	{
		sl->map[x][y] = c;
		if (c == 'W' || c == 'E' || c == 'S' || c == 'N')
		{
			sl->playerinfo.pos_x = x + 0.5;
			sl->playerinfo.pos_y = y + 0.5;
		}
	}
}

void	map_per_init(t_sl *sl, char *map_str)
{
	int		index;
	int		x;
	int		y;
	char	c;

	index = 0;
	y = 0;
	while (y < sl->mapinfo.y)
	{
		x = 0;
		while (x < sl->mapinfo.x)
		{
			c = map_str[index];
			x += map_end(sl, c, x, y);
			map_empty(sl, c, x, y);
			map_word(sl, c, x, y);
			x++;
			index++;
			if (x == sl->mapinfo.x)
				index++;
		}
		y++;
	}
}
