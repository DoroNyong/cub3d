/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:53:57 by hjang             #+#    #+#             */
/*   Updated: 2025/09/24 06:48:53 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_rotate_left(t_sl *sl)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = sl->playerinfo.dir_x;
	old_plane_x = sl->playerinfo.plane_x;
	angle = -sl->playerinfo.rot_speed;
	sl->playerinfo.dir_x = old_dir_x * cos(angle) - sl->playerinfo.dir_y \
							* sin(angle);
	sl->playerinfo.dir_y = old_dir_x * sin(angle) + sl->playerinfo.dir_y \
							* cos(angle);
	sl->playerinfo.plane_x = old_plane_x * cos(angle) \
							- sl->playerinfo.plane_y * sin(angle);
	sl->playerinfo.plane_y = old_plane_x * sin(angle) \
							+ sl->playerinfo.plane_y * cos(angle);
}

void	key_rotate_right(t_sl *sl)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = sl->playerinfo.dir_x;
	old_plane_x = sl->playerinfo.plane_x;
	angle = sl->playerinfo.rot_speed;
	sl->playerinfo.dir_x = old_dir_x * cos(angle) - sl->playerinfo.dir_y \
							* sin(angle);
	sl->playerinfo.dir_y = old_dir_x * sin(angle) + sl->playerinfo.dir_y \
							* cos(angle);
	sl->playerinfo.plane_x = old_plane_x * cos(angle) \
							- sl->playerinfo.plane_y * sin(angle);
	sl->playerinfo.plane_y = old_plane_x * sin(angle) \
							+ sl->playerinfo.plane_y * cos(angle);
}
