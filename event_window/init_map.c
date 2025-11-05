/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:45:32 by hjang             #+#    #+#             */
/*   Updated: 2025/11/05 18:10:00 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_init(t_sl *sl)
{
	sl->mapinfo.x = 0;
	sl->mapinfo.y = 0;
	sl->mapinfo.player_exists = 0;
	sl->map = NULL;
	sl->textures = NULL;
	sl->data.mlx = NULL;
	sl->data.win = NULL;
	sl->pixel.img = NULL;
	sl->config.no_path = NULL;
	sl->config.so_path = NULL;
	sl->config.we_path = NULL;
	sl->config.ea_path = NULL;
	sl->config.no_count = 0;
	sl->config.so_count = 0;
	sl->config.we_count = 0;
	sl->config.ea_count = 0;
	sl->config.c_color = -1;
	sl->config.f_color = -1;
	sl->config.c_count = 0;
	sl->config.f_count = 0;
}

void	sl_init_minimap(t_sl *sl)
{
	sl->minimap.fov = (2 * atan(0.66));
	sl->minimap.num_rays = 200;
	sl->minimap.ray_step = 0.05;
	sl->minimap.max_ray_dist = 30;
	sl->minimap.minimap_scale = 20;
	sl->anim.frame_count = 0;
	sl->anim.corrent_frame = 0;
}
