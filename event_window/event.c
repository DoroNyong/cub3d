/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:32:17 by hjang             #+#    #+#             */
/*   Updated: 2025/10/08 17:36:21 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(t_sl *sl)
{
	mlx_mouse_show(sl->data.mlx, sl->data.win);
	mlx_destroy_image(sl->data.mlx, sl->texture[0].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[1].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[2].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[3].img);
	mlx_destroy_image(sl->data.mlx, sl->pixel.img);
	mlx_destroy_window(sl->data.mlx, sl->data.win);
	mlx_destroy_display(sl->data.mlx);
	free(sl->data.mlx);
	free_map(sl, sl->mapinfo.x);
	if (sl->config.NO_path)
		free(sl->config.NO_path);
	if (sl->config.SO_path)
		free(sl->config.SO_path);
	if (sl->config.WE_path)
		free(sl->config.WE_path);
	if (sl->config.EA_path)
		free(sl->config.EA_path);
	exit(0);
	return (0);
}

int	game_loop(t_sl *sl)
{
	int	pressed;

	pressed = sl->keys.w + sl->keys.a + sl->keys.s + sl->keys.d;
	if (pressed == 2)
		sl->playerinfo.diag_speed = 1.0 / sqrt(2);
	else
		sl->playerinfo.diag_speed = 1.0;
	mouse_rotate(sl);
	if (sl->keys.w)
		key_move_w(sl);
	if (sl->keys.a)
		key_move_a(sl);
	if (sl->keys.s)
		key_move_s(sl);
	if (sl->keys.d)
		key_move_d(sl);
	if (sl->keys.left)
		key_rotate_left(sl);
	if (sl->keys.right)
		key_rotate_right(sl);
	if (sl->keys.esc)
		close_window(sl);
	make_screen(sl);
	return (0);
}
