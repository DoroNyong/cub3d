/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:33:42 by hjang             #+#    #+#             */
/*   Updated: 2025/09/26 17:15:10 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_surrounded(t_sl *sl, int x, int y)
{
	int	dx;
	int	dy;
	int	nx;
	int	ny;

	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			nx = x + dx;
			ny = y + dy;
			if (nx < 0 || ny < 0 || nx >= sl->mapinfo.x || ny >= sl->mapinfo.y)
				return (0);
			if (sl->map[nx][ny] == ' ')
				return (0);
			dy++;
		}
		dx++;
	}
	return (1);
}

int	is_surrounded(t_sl *sl, int x, int y)
{
	char	c;

	c = sl->map[x][y];
	if (c != '0' && c != 'W' && c != 'E' && c != 'S' && c != 'N')
		return (1);
	if (!check_surrounded(sl, x, y))
		return (0);
	return (1);
}

int	map_wall_check(t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	while (x < sl->mapinfo.x)
	{
		y = 0;
		while (y < sl->mapinfo.y)
		{
			if (!is_surrounded(sl, x, y))
			{
				printf("Error: map not closed at (%d, %d)\n", x, y);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
