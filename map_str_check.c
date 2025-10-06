/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:59:34 by hjang             #+#    #+#             */
/*   Updated: 2025/09/24 10:59:23 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	char_check(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '\n')
		return (0);
	else if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
		return (1);
	else
		return (2);
}

void	player_info_set(t_sl *sl, char c)
{
	if (c == 'W')
	{
		sl->playerinfo.dir_x = -1;
		sl->playerinfo.dir_y = 0;
		sl->playerinfo.plane_x = 0;
		sl->playerinfo.plane_y = -0.66;
	}
	else if (c == 'S')
	{
		sl->playerinfo.dir_x = 0;
		sl->playerinfo.dir_y = 1;
		sl->playerinfo.plane_x = -0.66;
		sl->playerinfo.plane_y = 0;
	}
	else if (c == 'N')
	{
		sl->playerinfo.dir_x = 0;
		sl->playerinfo.dir_y = -1;
		sl->playerinfo.plane_x = 0.66;
		sl->playerinfo.plane_y = 0;
	}
	else if (c == 'E')
	{
		sl->playerinfo.dir_x = 1;
		sl->playerinfo.dir_y = 0;
		sl->playerinfo.plane_x = 0;
		sl->playerinfo.plane_y = 0.66;
	}
}

int	map_validation(t_sl *sl, char *map_str)
{
	int	index;
	int	num;
	
	index = 0;
	while (map_str[index] != '\0')
	{
		num = char_check(map_str[index]);
		if (num == 1)
		{
			if (!sl->mapinfo.player_exists)
			{
				player_info_set(sl, map_str[index]);
				sl->mapinfo.player_exists = 1;
			}
			else
			{
				printf("Error\n%s\n", "플레이어는 하나만 존재해야 함");
				return (0);
			}
		}
		else if (num == 2)
		{
			printf("Error\n%s\n", "허용되지 않은 문자 발견");
			return (0);
		}
		index++;
	}
	return (1);
}

void	map_len(t_sl *sl, char *map_str)
{
	int	index;
	int	x;

	index = 0;
	x = 0;
	while (map_str[index] != '\0')
	{
		if (map_str[index] == '\n')
		{
			if (x > 0)
			{
				if (x > sl->mapinfo.x)
					sl->mapinfo.x = x;
			}
			sl->mapinfo.y++;
			x = 0;
		}
		else
			x++;
		index++;
	}
	if (x > 0)
	{
		if (x > sl->mapinfo.x)
			sl->mapinfo.x = x;
		sl->mapinfo.y++;
	}
}

int map_str_check(t_sl *sl, char *map_str)
{
	if (!map_validation(sl, map_str))
		return (0);
	if (!sl->mapinfo.player_exists)
	{
		printf("Error\n%s\n", "플레이어가 존재하지 않음");
		return (0);
	}
	map_len(sl, map_str);
	if (sl->mapinfo.x < 3 || sl->mapinfo.y < 3)
	{
		printf("Error\n%s\n", "맵 크기가 너무 작음");
		return (0);
	}
	return (1);
}
