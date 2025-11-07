/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str_check_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:25 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/05 16:46:32 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	update_map_info(t_sl *sl, int x)
{
	if (x > 0)
	{
		if (x > sl->mapinfo.x)
			sl->mapinfo.x = x;
		sl->mapinfo.y++;
	}
}

static void	process_map_line(t_sl *sl, char *map_str, int *index, int *x)
{
	while (map_str[*index] != '\0')
	{
		if (map_str[*index] == '\n')
		{
			if (*x > 0)
			{
				if (*x > sl->mapinfo.x)
					sl->mapinfo.x = *x;
			}
			sl->mapinfo.y++;
			*x = 0;
		}
		else
		{
			(*x)++;
		}
		(*index)++;
	}
}

void	map_len(t_sl *sl, char *map_str)
{
	int	index;
	int	x;

	index = 0;
	x = 0;
	process_map_line(sl, map_str, &index, &x);
	update_map_info(sl, x);
}
