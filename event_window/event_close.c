/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:50 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 16:46:50 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_textures(t_sl *sl)
{
	int	i;

	i = 0;
	if (sl->textures)
	{
		while (i < sl->total_tex_count)
		{
			if (sl->textures[i].img)
				mlx_destroy_image(sl->data.mlx, sl->textures[i].img);
			i++;
		}
		free(sl->textures);
	}
}

int	close_window(t_sl *sl)
{
	free_texture_paths(sl);
	free_map(sl, sl->mapinfo.x);
	free_textures(sl);
	mlx_mouse_show(sl->data.mlx, sl->data.win);
	mlx_destroy_image(sl->data.mlx, sl->pixel.img);
	mlx_destroy_window(sl->data.mlx, sl->data.win);
	mlx_destroy_display(sl->data.mlx);
	free(sl->data.mlx);
	exit(0);
	return (0);
}
