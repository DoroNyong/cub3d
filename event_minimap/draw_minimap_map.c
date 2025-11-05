/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:32:57 by hjang             #+#    #+#             */
/*   Updated: 2025/11/05 17:09:52 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

static void	draw_minimap_tile(t_sl *sl, int screen_x, int screen_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->minimap.minimap_scale)
	{
		j = 0;
		while (j < sl->minimap.minimap_scale)
		{
			my_mlx_pixel_put(&sl->pixel, screen_x + j, screen_y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_map(t_sl *sl)
{
	int	screen_x;
	int	screen_y;
	int	x;
	int	y;

	y = 0;
	while (y < sl->mapinfo.y)
	{
		x = 0;
		while (x < sl->mapinfo.x)
		{
			screen_x = x * sl->minimap.minimap_scale + \
				sl->minimap.minimap_scale;
			screen_y = y * sl->minimap.minimap_scale + \
				sl->minimap.minimap_scale;
			if (sl->map[x][y] == '1')
				draw_minimap_tile(sl, screen_x, screen_y, 0x333333);
			else if (sl->map[x][y] == ' ')
				;
			else
				draw_minimap_tile(sl, screen_x, screen_y, 0xAAAAAA);
			x++;
		}
		y++;
	}
}
