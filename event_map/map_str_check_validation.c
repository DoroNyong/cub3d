/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str_check_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:46 by byeolee           #+#    #+#             */
/*   Updated: 2025/11/29 13:23:39 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	char_check(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '\n')
		return (0);
	else if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
		return (1);
	else
		return (2);
}

static int	word_right(t_sl *sl, char ch)
{
	if (!sl->mapinfo.player_exists)
	{
		player_info_set(sl, ch);
		sl->mapinfo.player_exists = 1;
		return (1);
	}
	else
	{
		printf("Error\n%s\n", "Only one player is allowed.");
		return (0);
	}
}

static int	map_char_exist(char *map_str)
{
	int	index;
	int	checker;

	index = 0;
	checker = 0;
	while (map_str[index] != '\0')
	{
		if (ft_isdigit(map_str[index]))
			checker++;
		index++;
	}
	if (checker == 0)
	{
		printf("Error\n%s\n", "This is an empty file");
		return (0);
	}
	return (1);
}

int	map_validation(t_sl *sl, char *map_str)
{
	int	index;
	int	num;

	if (!map_char_exist(map_str))
		return (0);
	index = 0;
	while (map_str[index] != '\0')
	{
		num = char_check(map_str[index]);
		if (num == 1)
		{
			if (!word_right(sl, map_str[index]))
				return (0);
		}
		else if (num == 2)
		{
			printf("Error\n%s\n", "Invalid character detected.");
			return (0);
		}
		index++;
	}
	return (1);
}
