/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_make_screen2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:11:30 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 17:11:31 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	find_texture(t_sl *sl)
{
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
}

static void	calculate_wall(t_sl *sl)
{
	int	final_tex_idx;

	if (sl->draw.side == 0)
		sl->draw.wall_x = sl->playerinfo.pos_y \
			+ sl->draw.perp_wall_dist * sl->draw.ray_dir_y;
	else
		sl->draw.wall_x = sl->playerinfo.pos_x \
			+ sl->draw.perp_wall_dist * sl->draw.ray_dir_x;
	sl->draw.wall_x -= floor(sl->draw.wall_x);
	if (sl->tex_counts[sl->draw.tex_dir] > 0)
	{
		final_tex_idx = sl->tex_offsets[sl->draw.tex_dir] + \
			(sl->anim.corrent_frame % sl->tex_counts[sl->draw.tex_dir]);
	}
	else
		final_tex_idx = 0;
	sl->draw.tex_x = (int)(sl->draw.wall_x * \
		(double)sl->textures[final_tex_idx].width);
	if (sl->draw.side == 0 && sl->draw.ray_dir_x < 0)
		sl->draw.tex_x = sl->textures[final_tex_idx].width - sl->draw.tex_x - 1;
	if (sl->draw.side == 1 && sl->draw.ray_dir_y > 0)
		sl->draw.tex_x = sl->textures[final_tex_idx].width - sl->draw.tex_x - 1;
}

void	draw_texture(t_sl *sl, int x)
{
	find_texture(sl);
	calculate_wall(sl);
	draw_vertical_line(sl, x);
}
