/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_make_screen_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:04:51 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 17:10:26 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length \
			+ x * (pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_sl *sl, int x)
{
	draw_background_line(sl, x);
	draw_textures_line(sl, x);
	draw_bottom_line(sl, x);
}
