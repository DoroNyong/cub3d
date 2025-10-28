/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:45:32 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 02:04:15 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_init(t_sl *sl)
{
	sl->mapinfo.x = 0;
	sl->mapinfo.y = 0;
	sl->mapinfo.player_exists = 0;
	sl->map = NULL;
}

void	load_texures(t_sl *sl)
{
	sl->texture[0].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_n_1.xpm", &(sl->texture[0].width), &(sl->texture[0].height));
	sl->texture[0].addr = mlx_get_data_addr(sl->texture[0].img, &sl->texture[0].bits_per_pixel \
			, &sl->texture[0].line_length, &sl->texture[0].endian);
	sl->texture[1].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_n_2.xpm", &(sl->texture[1].width), &(sl->texture[1].height));
	sl->texture[1].addr = mlx_get_data_addr(sl->texture[1].img, &sl->texture[1].bits_per_pixel \
			, &sl->texture[1].line_length, &sl->texture[1].endian);
	sl->texture[2].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_n_3.xpm", &(sl->texture[2].width), &(sl->texture[2].height));
	sl->texture[2].addr = mlx_get_data_addr(sl->texture[2].img, &sl->texture[2].bits_per_pixel \
			, &sl->texture[2].line_length, &sl->texture[2].endian);
	sl->texture[3].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_s_1.xpm", &(sl->texture[3].width), &(sl->texture[3].height));
	sl->texture[3].addr = mlx_get_data_addr(sl->texture[3].img, &sl->texture[3].bits_per_pixel \
			, &sl->texture[3].line_length, &sl->texture[3].endian);
	sl->texture[4].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_s_2.xpm", &(sl->texture[4].width), &(sl->texture[4].height));
	sl->texture[4].addr = mlx_get_data_addr(sl->texture[4].img, &sl->texture[4].bits_per_pixel \
			, &sl->texture[4].line_length, &sl->texture[4].endian);
	sl->texture[5].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_s_3.xpm", &(sl->texture[5].width), &(sl->texture[5].height));
	sl->texture[5].addr = mlx_get_data_addr(sl->texture[5].img, &sl->texture[5].bits_per_pixel \
			, &sl->texture[5].line_length, &sl->texture[5].endian);
	sl->texture[6].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_w_1.xpm", &(sl->texture[6].width), &(sl->texture[6].height));
	sl->texture[6].addr = mlx_get_data_addr(sl->texture[6].img, &sl->texture[6].bits_per_pixel \
			, &sl->texture[6].line_length, &sl->texture[6].endian);
	sl->texture[7].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_w_2.xpm", &(sl->texture[7].width), &(sl->texture[7].height));
	sl->texture[7].addr = mlx_get_data_addr(sl->texture[7].img, &sl->texture[7].bits_per_pixel \
			, &sl->texture[7].line_length, &sl->texture[7].endian);
	sl->texture[8].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_w_3.xpm", &(sl->texture[8].width), &(sl->texture[8].height));
	sl->texture[8].addr = mlx_get_data_addr(sl->texture[8].img, &sl->texture[8].bits_per_pixel \
			, &sl->texture[8].line_length, &sl->texture[8].endian);
	sl->texture[9].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_e_1.xpm", &(sl->texture[9].width), &(sl->texture[9].height));
	sl->texture[9].addr = mlx_get_data_addr(sl->texture[9].img, &sl->texture[9].bits_per_pixel \
			, &sl->texture[9].line_length, &sl->texture[9].endian);
	sl->texture[10].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_e_2.xpm", &(sl->texture[10].width), &(sl->texture[10].height));
	sl->texture[10].addr = mlx_get_data_addr(sl->texture[10].img, &sl->texture[10].bits_per_pixel \
			, &sl->texture[10].line_length, &sl->texture[10].endian);
	sl->texture[11].img = mlx_xpm_file_to_image(sl->data.mlx \
			, "./textures/wall_e_3.xpm", &(sl->texture[11].width), &(sl->texture[11].height));
	sl->texture[11].addr = mlx_get_data_addr(sl->texture[11].img, &sl->texture[11].bits_per_pixel \
			, &sl->texture[11].line_length, &sl->texture[11].endian);
}

void	sl_init(t_sl *sl)
{
	sl->data.mlx = mlx_init();
	sl->data.screen_width = 800;
	sl->data.screen_height = 450;
	sl->data.win = mlx_new_window(sl->data.mlx, sl->data.screen_width \
									, sl->data.screen_height, "cub3d");
	mlx_mouse_move(sl->data.mlx, sl->data.win, sl->data.screen_width / 2, sl->data.screen_height / 2);
	// mlx_mouse_hide(sl->data.mlx, sl->data.win);
	// valgrind still reachable 주범
	sl->pixel.img = mlx_new_image(sl->data.mlx, sl->data.screen_width, sl->data.screen_height);
	sl->pixel.addr = mlx_get_data_addr(sl->pixel.img, &sl->pixel.bits_per_pixel, &sl->pixel.line_length, &sl->pixel.endian);
	sl->playerinfo.move_speed = 0.002;
	sl->playerinfo.rot_speed = 0.001;
	sl->keys.w = 0;
	sl->keys.a = 0;
	sl->keys.s = 0;
	sl->keys.d = 0;
	sl->keys.left = 0;
	sl->keys.right = 0;
	sl->keys.esc = 0;
	sl->mouse.prev_x = -1;
	sl->mouse.smooth_dx = 0.0;
	sl->mouse.prev_x = sl->data.screen_width / 2;
	sl->minimap.fov = (2 * atan(0.66));
	sl->minimap.num_rays = 200;
	sl->minimap.ray_step = 0.05;
	sl->minimap.max_ray_dist = 30;
	sl->minimap.minimap_scale = 20;
	sl->anim.frame_count = 0;
	sl->anim.corrent_frame = 0;
	load_texures(sl);
	make_screen(sl);
}
