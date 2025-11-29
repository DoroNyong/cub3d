/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_setting_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:16 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/29 13:32:30 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	parse_color(int *color, char *line)
{
	char	**rgb_values;
	t_rgb	colors;
	int		i;

	rgb_values = ft_split(line, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || \
		!rgb_values[2] || rgb_values[3])
	{
		printf("Error\n%s\n", "Invalid RGB color format.");
		exit(1);
	}
	colors.r = ft_atoi(rgb_values[0]);
	colors.g = ft_atoi(rgb_values[1]);
	colors.b = ft_atoi(rgb_values[2]);
	i = 0;
	while (rgb_values[i])
		free(rgb_values[i++]);
	free(rgb_values);
	if (colors.r < 0 || colors.r > 255 || colors.g < 0 || colors.g > 255 || \
		colors.b < 0 || colors.b > 255)
	{
		printf("Error\n%s\n", "RGB values must be between 0 and 255.");
		exit(1);
	}
	*color = (colors.r << 16) + (colors.g << 8) + colors.b;
}

int	parsing_colors(t_sl *sl, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		sl->config.f_count++;
		parse_color(&sl->config.f_color, line + 2);
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		sl->config.c_count++;
		parse_color(&sl->config.c_color, line + 2);
		return (1);
	}
	return (0);
}
