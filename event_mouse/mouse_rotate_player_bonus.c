/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate_player_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:02:00 by hjang             #+#    #+#             */
/*   Updated: 2025/10/06 16:29:31 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
