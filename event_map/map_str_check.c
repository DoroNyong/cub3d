/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:59:34 by hjang             #+#    #+#             */
/*   Updated: 2025/11/29 13:23:37 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_str_check(t_sl *sl, char *map_str)
{
	if (!map_validation(sl, map_str))
		return (0);
	if (!sl->mapinfo.player_exists)
	{
		printf("Error\n%s\n", "Player does not exist.");
		return (0);
	}
	map_len(sl, map_str);
	if (sl->mapinfo.x < 3 || sl->mapinfo.y < 3)
	{
		printf("Error\n%s\n", "Map dimensions are too small.");
		return (0);
	}
	return (1);
}
