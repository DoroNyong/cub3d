/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:24:11 by hjang             #+#    #+#             */
/*   Updated: 2025/10/30 18:08:57 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_check(t_sl *sl, char *map_name)
{
	char	*full_file;
	char	**lines;

	map_exception(map_name, &full_file, &lines);
	parse_config_lines(sl, lines);
	process_map_lines(sl, lines, full_file);
}
