/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:02:00 by hjang             #+#    #+#             */
/*   Updated: 2025/09/26 17:14:15 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_sl *sl, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = sl->playerinfo.dir_x;
	old_plane_x = sl->playerinfo.plane_x;
	sl->playerinfo.dir_x = old_dir_x * cos(angle) - sl->playerinfo.dir_y \
							* sin(angle);
	sl->playerinfo.dir_y = old_dir_x * sin(angle) + sl->playerinfo.dir_y \
							* cos(angle);
	sl->playerinfo.plane_x = old_plane_x * cos(angle) \
							- sl->playerinfo.plane_y * sin(angle);
	sl->playerinfo.plane_y = old_plane_x * sin(angle) \
							+ sl->playerinfo.plane_y * cos(angle);
}

void	mouse_rotate(t_sl *sl)
{
	int	x;
	int	y;
	int	center_x;
	int	center_y;
	int	delta;
	double	d;
	double	smo_al = 0.25;
	double	sen = 0.002;
	int	reset = 100;

	center_x = sl->data.screen_width / 2;
	center_y = sl->data.screen_height / 2;
	mlx_mouse_get_pos(sl->data.mlx, sl->data.win, &x, &y);
	delta = x - sl->mouse.prev_x;
	if (delta > 60)
		delta = 60;
	if (delta < -60)
		delta = -60;
	sl->mouse.prev_x = x;
	sl->mouse.smooth_dx = smo_al * (double)delta + (1.0 - smo_al) * sl->mouse.smooth_dx;
	d = sl->mouse.smooth_dx * sen;
	if (d != 0.0)
		rotate_player(sl, d);
	if (abs(x - center_x) >= reset)
	{
		mlx_mouse_move(sl->data.mlx, sl->data.win, center_x, center_y);
		sl->mouse.prev_x = center_x;

		sl->mouse.smooth_dx = 0.0;
	}
}
