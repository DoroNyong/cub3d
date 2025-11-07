/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:02:00 by hjang             #+#    #+#             */
/*   Updated: 2025/10/06 16:31:35 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_mouse_data(t_sl *sl, int *x, int *y)
{
	int	delta;

	mlx_mouse_get_pos(sl->data.mlx, sl->data.win, x, y);
	delta = *x - sl->mouse.prev_x;
	if (delta > 60)
		delta = 60;
	if (delta < -60)
		delta = -60;
	sl->mouse.prev_x = *x;
	return (delta);
}

static double	apply_smoothing(t_sl *sl, int delta)
{
	double	smo_al;

	smo_al = 0.25;
	sl->mouse.smooth_dx = smo_al * delta + (1.0 - smo_al) * sl->mouse.smooth_dx;
	return (sl->mouse.smooth_dx);
}

static void	reset_mouse_if_needed(t_sl *sl)
{
	int	center_x;
	int	center_y;

	center_x = sl->data.screen_width / 2;
	center_y = sl->data.screen_height / 2;
	if (abs(sl->mouse.prev_x - center_x) >= 100)
	{
		mlx_mouse_move(sl->data.mlx, sl->data.win, center_x, center_y);
		sl->mouse.prev_x = center_x;
		sl->mouse.smooth_dx = 0.0;
	}
}

static void	preprocess_values(t_sl *sl, double *d)
{
	int	x;
	int	y;
	int	delta;

	delta = get_mouse_data(sl, &x, &y);
	sl->mouse.smooth_dx = apply_smoothing(sl, delta);
	*d = sl->mouse.smooth_dx * 0.002;
	reset_mouse_if_needed(sl);
}

void	mouse_rotate(t_sl *sl)
{
	double	d;

	preprocess_values(sl, &d);
	if (d != 0.0)
		rotate_player(sl, d);
}
