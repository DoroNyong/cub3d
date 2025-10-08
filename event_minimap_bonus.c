/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:32:57 by hjang             #+#    #+#             */
/*   Updated: 2025/10/09 05:55:33 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	draw_minimap_tile(t_sl *sl, int screen_x, int screen_y, int color)
{
	int i;
	int j;
	
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
#define MAX_RAY_DIST 20

void	draw_minimap_ray(t_sl *sl, double ray_dir_x, double ray_dir_y)
{
	double ray_x;
	double ray_y;
	double dist;

	ray_x = sl->playerinfo.pos_x;
	ray_y = sl->playerinfo.pos_y;
	dist = 0;
	while (dist < sl->minimap.max_ray_dist)
	{
		ray_x += ray_dir_x * sl->minimap.ray_step;
		ray_y += ray_dir_y * sl->minimap.ray_step;
		dist += sl->minimap.ray_step;
		if (sl->map[(int)ray_x][(int)ray_y] == '1')
			break ;
		int screen_x = (int)(ray_x * sl->minimap.minimap_scale) + sl->minimap.minimap_scale;
		int screen_y = (int)(ray_y * sl->minimap.minimap_scale) + sl->minimap.minimap_scale;
		my_mlx_pixel_put(&sl->pixel, screen_x, screen_y, 0xFF0000);
	}
}

void	draw_minimap_fov(t_sl *sl)
{
	// 플레이어의 기본 방향
	double dir_x = sl->playerinfo.dir_x;
	double dir_y = sl->playerinfo.dir_y;

	// 각 레이마다 회전값 적용
	double angle_start = -sl->minimap.fov / 2;
	double angle_step = sl->minimap.fov / sl->minimap.num_rays;

	for (int i = 0; i < sl->minimap.num_rays; i++)
	{
		double ray_angle = angle_start + angle_step * i;

		// 회전 행렬 적용
		double ray_dir_x = dir_x * cos(ray_angle) - dir_y * sin(ray_angle);
		double ray_dir_y = dir_x * sin(ray_angle) + dir_y * cos(ray_angle);

		draw_minimap_ray(sl, ray_dir_x, ray_dir_y);
	}
}

void	draw_minimap(t_sl *sl)
{
	int	x;
	int	y;

	// 맵 찍기
	y = 0;
	while (y < sl->mapinfo.y)
	{
		x = 0;
		while (x < sl->mapinfo.x)
		{
			int	screen_x = x * sl->minimap.minimap_scale + sl->minimap.minimap_scale;
			int	screen_y = y * sl->minimap.minimap_scale + sl->minimap.minimap_scale;
			if (sl->map[x][y] == '1')
				draw_minimap_tile(sl, screen_x, screen_y, 0x333333);
			else if (sl->map[x][y] == ' ')
			{
				x++;
				continue ;
			}
			else
				draw_minimap_tile(sl, screen_x, screen_y, 0xAAAAAA);
			x++;
		}
		y++;
	}
	
	// 플레이어 찍기
	int	player_screen_x = (int)(sl->playerinfo.pos_x * sl->minimap.minimap_scale) + sl->minimap.minimap_scale;;
	int	player_screen_y = (int)(sl->playerinfo.pos_y * sl->minimap.minimap_scale) + sl->minimap.minimap_scale;;
	my_mlx_pixel_put(&sl->pixel, player_screen_x, player_screen_y, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x - 1, player_screen_y, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x + 1, player_screen_y, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x, player_screen_y - 1, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x, player_screen_y + 1, 0xFF0000);
	// draw_minimap_tile(sl, player_screen_x, player_screen_y, 0xFF0000);

	// 광선 찍기
	draw_minimap_fov(sl);
}
