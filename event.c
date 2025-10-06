/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:32:17 by hjang             #+#    #+#             */
/*   Updated: 2025/10/02 15:43:14 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_sl *sl)
{
	mlx_destroy_image(sl->data.mlx, sl->texture[0].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[1].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[2].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[3].img);
	mlx_destroy_image(sl->data.mlx, sl->pixel.img);
	mlx_destroy_window(sl->data.mlx, sl->data.win);
	mlx_destroy_display(sl->data.mlx);
	free(sl->data.mlx);
	free_map(sl, sl->mapinfo.x);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length + x * (pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_vertical_line(t_sl *sl, int x)
{
	int	index;

	index =0;
	while (index < sl->draw.start)
	{
		my_mlx_pixel_put(&sl->pixel, x, index, 0x000080);
		index++;
	}
	// printf("함수안에서 x = %d, start = %d\n", x, sl->draw.start);
	sl->draw.step = 1.0 * sl->texture[sl->draw.tex_dir].height / sl->draw.line_height;
	sl->draw.tex_pos = (sl->draw.start - sl->data.screen_height / 2 + sl->draw.line_height / 2) * sl->draw.step;
    // while (sl->draw.start <= sl->draw.end)
    // {
    //     my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->draw.color);
    //     sl->draw.start++;
    // }
	while (sl->draw.start <= sl->draw.end)
    {
		sl->draw.tex_y = (int)sl->draw.tex_pos % sl->texture[sl->draw.tex_dir].height;
		sl->draw.tex_pos += sl->draw.step;

		sl->draw.tex_pixel = sl->texture[sl->draw.tex_dir].addr + (sl->draw.tex_y * sl->texture[sl->draw.tex_dir].line_length + sl->draw.tex_x * (sl->texture[sl->draw.tex_dir].bits_per_pixel / 8));
		sl->draw.color = *(unsigned int *)sl->draw.tex_pixel;
		
		my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->draw.color);
		sl->draw.start++;
    }
	while (sl->draw.start <= sl->data.screen_height)
	{
		my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, 0x8B0000);
        sl->draw.start++;
	}
	// printf("함수끝날때 start = %d\n", sl->draw.start);
}

void	make_screen(t_sl *sl)
{
	int	x;

	x = 0;
	while (x < sl->data.screen_width)
	{
		sl->draw.camera_x = 2 * x / (double)sl->data.screen_width - 1;
		sl->draw.ray_dir_x = sl->playerinfo.dir_x + sl->playerinfo.plane_x * sl->draw.camera_x;
		sl->draw.ray_dir_y = sl->playerinfo.dir_y + sl->playerinfo.plane_y * sl->draw.camera_x;

		sl->draw.map_x = (int)sl->playerinfo.pos_x;
		sl->draw.map_y = (int)sl->playerinfo.pos_y;

		sl->draw.delta_dist_x = (sl->draw.ray_dir_x == 0) ? 1e30 : fabs(1 / sl->draw.ray_dir_x);
		sl->draw.delta_dist_y = (sl->draw.ray_dir_y == 0) ? 1e30 : fabs(1 / sl->draw.ray_dir_y);

		sl->draw.hit = 0;
		if (sl->draw.ray_dir_x < 0)
		{
			sl->draw.step_x = -1;
			sl->draw.side_dist_x = (sl->playerinfo.pos_x - sl->draw.map_x) * sl->draw.delta_dist_x;
		}
		else
		{
			sl->draw.step_x = 1;
			sl->draw.side_dist_x = (sl->draw.map_x + 1.0 - sl->playerinfo.pos_x) * sl->draw.delta_dist_x;
		}
		if (sl->draw.ray_dir_y < 0)
		{
			sl->draw.step_y = -1;
			sl->draw.side_dist_y = (sl->playerinfo.pos_y - sl->draw.map_y) * sl->draw.delta_dist_y;
		}
		else
		{
			sl->draw.step_y = 1;
			sl->draw.side_dist_y = (sl->draw.map_y + 1.0 - sl->playerinfo.pos_y) * sl->draw.delta_dist_y;
		}

		while (sl->draw.hit == 0)
		{
			if (sl->draw.side_dist_x < sl->draw.side_dist_y)
			{
				sl->draw.side_dist_x += sl->draw.delta_dist_x;
				sl->draw.map_x += sl->draw.step_x;
				sl->draw.side = 0;
			}
			else
			{
				sl->draw.side_dist_y += sl->draw.delta_dist_y;
				sl->draw.map_y += sl->draw.step_y;
				sl->draw.side = 1;
			}
			if (sl->map[sl->draw.map_x][sl->draw.map_y] == '1')
				sl->draw.hit = 1;
		}

		if (sl->draw.side == 0)
			sl->draw.perp_wall_dist = (sl->draw.map_x - sl->playerinfo.pos_x + (1 - sl->draw.step_x) / 2) / sl->draw.ray_dir_x;
		else
			sl->draw.perp_wall_dist = (sl->draw.map_y - sl->playerinfo.pos_y + (1 - sl->draw.step_y) / 2) / sl->draw.ray_dir_y;

		sl->draw.line_height = (int)(sl->data.screen_height / sl->draw.perp_wall_dist);
		// printf("x = %d, player_pos = %f, %f, side = %d\n", x, sl->playerinfo.pos_x, sl->playerinfo.pos_y, sl->draw.side);
		// printf("delta_x = %f, delta_y = %f, perp_wall_dist = %f\n", sl->draw.delta_dist_x, sl->draw.delta_dist_y, sl->draw.perp-wall_dist);
		sl->draw.start = -sl->draw.line_height / 2 + sl->data.screen_height / 2;
		if (sl->draw.start < 0)
			sl->draw.start = 0;
		sl->draw.end = sl->draw.line_height / 2 + sl->data.screen_height / 2;
		if (sl->draw.end >= sl->data.screen_height)
			sl->draw.end = sl->data.screen_height - 1;
		// printf("start = %d, end = %d\n", sl->draw.start, sl->draw.end);
		// if (sl->draw.side == 0)
		// {
		// 	if (sl->draw.step_x > 0)
		// 		sl->draw.color = 0x00FF00;
		// 	else
		// 		sl->draw.color = 0xFFFF00;
		// }
		// else
		// {
		// 	if (sl->draw.step_y > 0)
		// 		sl->draw.color = 0xFFFFFF;
		// 	else
		// 		sl->draw.color = 0xAAAAAA;
		// }
		if (sl->draw.side == 0)
		{
			if (sl->draw.step_x > 0)
				sl->draw.tex_dir = W;
			else
				sl->draw.tex_dir = E;
		}
		else
		{
			if (sl->draw.step_y > 0)
				sl->draw.tex_dir = N;
			else
				sl->draw.tex_dir = S;
		}

		if (sl->draw.side == 0)
			sl->draw.wall_x = sl->playerinfo.pos_y + sl->draw.perp_wall_dist * sl->draw.ray_dir_y;
		else
			sl->draw.wall_x = sl->playerinfo.pos_x + sl->draw.perp_wall_dist * sl->draw.ray_dir_x;
		sl->draw.wall_x -= floor(sl->draw.wall_x);
		
		sl->draw.tex_x = (int)(sl->draw.wall_x * (double)sl->texture[sl->draw.tex_dir].width);
		if (sl->draw.side == 0 && sl->draw.ray_dir_x < 0)
			sl->draw.tex_x = sl->texture[sl->draw.tex_dir].width - sl->draw.tex_x - 1;
		if (sl->draw.side == 1 && sl->draw.ray_dir_y > 0)
			sl->draw.tex_x = sl->texture[sl->draw.tex_dir].width - sl->draw.tex_x - 1;
		draw_vertical_line(sl, x);
		x++;
	}
	mlx_put_image_to_window(sl->data.mlx, sl->data.win, sl->pixel.img, 0, 0);
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
