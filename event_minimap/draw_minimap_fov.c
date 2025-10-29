/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_fov.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:32:57 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 17:10:51 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

static void	draw_minimap_ray(t_sl *sl, double ray_dir_x, double ray_dir_y)
{
	double	ray_x;
	double	ray_y;
	double	dist;
	int		screen_x;
	int		screen_y;

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
		screen_x = (int)(ray_x * sl->minimap.minimap_scale) + \
			sl->minimap.minimap_scale;
		screen_y = (int)(ray_y * sl->minimap.minimap_scale) + \
			sl->minimap.minimap_scale;
		my_mlx_pixel_put(&sl->pixel, screen_x, screen_y, 0xFF0000);
	}
}

static void	draw_fov_ray(t_sl *sl, t_ray *ray)
{
	int		i;
	double	ray_angle;
	double	ray_dir_x;
	double	ray_dir_y;

	i = 0;
	while (i < sl->minimap.num_rays)
	{
		ray_angle = ray->angle_start + ray->angle_step * i;
		ray_dir_x = ray->dir_x * cos(ray_angle) - ray->dir_y * sin(ray_angle);
		ray_dir_y = ray->dir_x * sin(ray_angle) + ray->dir_y * cos(ray_angle);
		draw_minimap_ray(sl, ray_dir_x, ray_dir_y);
		i++;
	}
}

void	draw_minimap_fov(t_sl *sl)
{
	t_ray	ray;

	ray.dir_x = sl->playerinfo.dir_x;
	ray.dir_y = sl->playerinfo.dir_y;
	ray.angle_start = -sl->minimap.fov / 2;
	ray.angle_step = sl->minimap.fov / sl->minimap.num_rays;
	draw_fov_ray(sl, &ray);
}
