/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str_check_setting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:42 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 16:46:44 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	char_w(t_sl *sl)
{
	sl->playerinfo.dir_x = -1;
	sl->playerinfo.dir_y = 0;
	sl->playerinfo.plane_x = 0;
	sl->playerinfo.plane_y = -0.66;
}

static void	char_s(t_sl *sl)
{
	sl->playerinfo.dir_x = 0;
	sl->playerinfo.dir_y = 1;
	sl->playerinfo.plane_x = -0.66;
	sl->playerinfo.plane_y = 0;
}

static void	char_n(t_sl *sl)
{
	sl->playerinfo.dir_x = 0;
	sl->playerinfo.dir_y = -1;
	sl->playerinfo.plane_x = 0.66;
	sl->playerinfo.plane_y = 0;
}

static void	char_e(t_sl *sl)
{
	sl->playerinfo.dir_x = 1;
	sl->playerinfo.dir_y = 0;
	sl->playerinfo.plane_x = 0;
	sl->playerinfo.plane_y = 0.66;
}

void	player_info_set(t_sl *sl, char c)
{
	if (c == 'W')
		char_w(sl);
	else if (c == 'S')
		char_s(sl);
	else if (c == 'N')
		char_n(sl);
	else if (c == 'E')
		char_e(sl);
}
