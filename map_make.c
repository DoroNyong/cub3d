/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:27:44 by hjang             #+#    #+#             */
/*   Updated: 2025/10/06 12:54:43 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map, int width, int height)
{
	int y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			printf("%c", map[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	map_init1(t_sl *sl, char *map_str)
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
			if (c == '\n' || c == '\0')
			{
				while (x < sl->mapinfo.x)
					sl->map[x++][y] = ' ';
			}
			if (c == ' ')
				sl->map[x][y] = ' ';
			if (c == 'W' || c == 'E' || c == 'S' || c == 'N' || c == '0' || c == '1')
			{
				sl->map[x][y] = c;
				if (c == 'W' || c == 'E' || c == 'S' || c == 'N')
				{
					sl->playerinfo.pos_x = x + 0.5;
					sl->playerinfo.pos_y = y + 0.5;
				}
			}
			x++;
			index++;
			if (x == sl->mapinfo.x)
				index++;
		}
		y++;
	}
	print_map(sl->map, sl->mapinfo.x, sl->mapinfo.y);
}

int map_make_1(t_sl *sl)
{
	sl->map = (char **)malloc(sizeof(char *) * (sl->mapinfo.x + 1));
	if (!sl->map)
		return (0);
	sl->map[sl->mapinfo.x] = NULL;
	return (1);
}

int map_make_2(t_sl *sl)
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
	map_init1(sl, map_str);
	// 함수이름 수정필요
	if (!map_wall_check(sl))
	{
		free_map(sl, sl->mapinfo.x);
		return (0);
	}
	return (1);
}
