/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:45:32 by hjang             #+#    #+#             */
/*   Updated: 2025/10/08 17:09:21 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_init(t_sl *sl)
{
	sl->mapinfo.x = 0;
	sl->mapinfo.y = 0;
	sl->mapinfo.player_exists = 0;
	sl->map = NULL;
	sl->config.NO_path = ft_strdup("./textures/wall_n.xpm");
	sl->config.SO_path = ft_strdup("./textures/wall_s.xpm");
	sl->config.WE_path = ft_strdup("./textures/wall_w.xpm");
	sl->config.EA_path = ft_strdup("./textures/wall_e.xpm");
	sl->config.C_color = 0x000080;
	sl->config.F_color = 0x8B0000;
}
