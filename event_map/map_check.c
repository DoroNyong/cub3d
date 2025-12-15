/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:24:11 by hjang             #+#    #+#             */
/*   Updated: 2025/12/15 15:18:25 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_check(t_sl *sl, char *map_name)
{
	char	*full_file;
	char	**lines;
	int		map_start_idx;

	map_exception(map_name, &full_file, &lines);
	sl->full_file = full_file;
	map_start_idx = parse_config_lines(sl, lines);
	map_empty_line_check(sl, full_file, lines, map_start_idx);
	process_map_lines(sl, lines, map_start_idx);
	if (sl->full_file)
	{
		free(sl->full_file);
		sl->full_file = NULL;
	}
}
