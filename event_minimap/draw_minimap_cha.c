/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_cha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:32:57 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 17:01:30 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	draw_minimap_cha(t_sl *sl)
{
	int	player_screen_x;
	int	player_screen_y;

	player_screen_x = (int)(sl->playerinfo.pos_x * \
		sl->minimap.minimap_scale) + \
		sl->minimap.minimap_scale;
	player_screen_y = (int)(sl->playerinfo.pos_y * \
		sl->minimap.minimap_scale) + \
		sl->minimap.minimap_scale;
	my_mlx_pixel_put(&sl->pixel, player_screen_x, \
		player_screen_y, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x - 1, \
		player_screen_y, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x + 1, \
		player_screen_y, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x, \
		player_screen_y - 1, 0xFF0000);
	my_mlx_pixel_put(&sl->pixel, player_screen_x, \
		player_screen_y + 1, 0xFF0000);
}
