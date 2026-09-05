/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_make_screen_line_per.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:37 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 17:17:37 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_background_line(t_sl *sl, int x)
{
	int	index;

	index = 0;
	while (index < sl->draw.start)
	{
		my_mlx_pixel_put(&sl->pixel, x, index, sl->config.c_color);
		index++;
	}
}

static void	render_texture_line(t_sl *sl, int x, int final_tex_idx)
{
	while (sl->draw.start <= sl->draw.end - 1)
	{
		sl->draw.tex_y = (int)sl->draw.tex_pos % \
			sl->textures[final_tex_idx].height;
		sl->draw.tex_pos += sl->draw.step;
		sl->draw.tex_pixel = sl->textures[final_tex_idx].addr + \
			(sl->draw.tex_y * sl->textures[final_tex_idx].line_length + \
			sl->draw.tex_x * (sl->textures[final_tex_idx].bits_per_pixel / 8));
		sl->draw.color = *(unsigned int *)sl->draw.tex_pixel;
		my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->draw.color);
		sl->draw.start++;
	}
}

void	draw_textures_line(t_sl *sl, int x)
{
	int	final_tex_idx;

	if (sl->tex_counts[sl->draw.tex_dir] > 0)
	{
		final_tex_idx = sl->tex_offsets[sl->draw.tex_dir] + \
			(sl->anim.corrent_frame % sl->tex_counts[sl->draw.tex_dir]);
	}
	else
		final_tex_idx = 0;
	sl->draw.step = 1.0 * sl->textures[final_tex_idx].height / \
		sl->draw.line_height;
	sl->draw.tex_pos = (sl->draw.start - sl->data.screen_height \
		/ 2 + sl->draw.line_height / 2) * sl->draw.step;
	render_texture_line(sl, x, final_tex_idx);
	my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->draw.color);
	sl->draw.start++;
}

void	draw_bottom_line(t_sl *sl, int x)
{
	while (sl->draw.start <= sl->data.screen_height)
	{
		my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->config.f_color);
		sl->draw.start++;
	}
}
