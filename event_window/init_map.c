/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:45:32 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 15:39:26 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_init(t_sl *sl)
{
	sl->mapinfo.x = 0;
	sl->mapinfo.y = 0;
	sl->mapinfo.player_exists = 0;
	sl->map = NULL;
	sl->config.NO_path = NULL;
	sl->config.SO_path = NULL;
	sl->config.WE_path = NULL;
	sl->config.EA_path = NULL;
	sl->config.C_color = -1;
	sl->config.F_color = -1;
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
