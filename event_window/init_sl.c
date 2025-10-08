/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:45:32 by hjang             #+#    #+#             */
/*   Updated: 2025/10/08 17:27:58 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	sl_init_data(t_sl *sl)
{
	sl->data.mlx = mlx_init();
	sl->data.screen_width = 800;
	sl->data.screen_height = 450;
	sl->data.win = mlx_new_window(
			sl->data.mlx,
			sl->data.screen_width,
			sl->data.screen_height,
			"cub3d");
	mlx_mouse_move(
		sl->data.mlx,
		sl->data.win,
		sl->data.screen_width / 2,
		sl->data.screen_height / 2);
}

static void	sl_init_keys(t_sl *sl)
{
	sl->keys.w = 0;
	sl->keys.a = 0;
	sl->keys.s = 0;
	sl->keys.d = 0;
	sl->keys.left = 0;
	sl->keys.right = 0;
	sl->keys.esc = 0;
}

static void	sl_init_mouse(t_sl *sl)
{
	sl->mouse.prev_x = -1;
	sl->mouse.smooth_dx = 0.0;
	sl->mouse.prev_x = sl->data.screen_width / 2;
	mlx_mouse_hide(sl->data.mlx, sl->data.win);
}

static void	sl_init_etc(t_sl *sl)
{
	sl->pixel.img = mlx_new_image(
			sl->data.mlx,
			sl->data.screen_width,
			sl->data.screen_height);
	sl->pixel.addr = mlx_get_data_addr(
			sl->pixel.img,
			&sl->pixel.bits_per_pixel,
			&sl->pixel.line_length,
			&sl->pixel.endian);
	sl->playerinfo.move_speed = 0.002;
	sl->playerinfo.rot_speed = 0.001;
}

void	sl_init(t_sl *sl)
{
	sl_init_data(sl);
	sl_init_keys(sl);
	sl_init_mouse(sl);
	sl_init_etc(sl);
	load_texures(sl);
	make_screen(sl);
}
