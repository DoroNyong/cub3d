/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:24:11 by hjang             #+#    #+#             */
/*   Updated: 2025/09/16 16:10:13 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_error(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

int	check_map_name(char *map_name)
{
	int	len;

	len = 0;
	while (map_name[len])
		len++;
	if (!(map_name[len - 1] == 'b' && map_name[len - 2] == 'u' \
		&& map_name[len - 3] == 'c' && map_name[len - 4] == '.'))
		return (0);
	if (!((map_name[len - 5] >= 'a' && map_name[len - 5] <= 'z') \
		|| (map_name[len - 5] >= 'A' && map_name[len - 5] <= 'Z') \
		|| (map_name[len - 5] >= '0' && map_name[len - 5] <= '9')))
		return (0);
	return (1);
}

char	*read_map(int fd)
{
	char	buf[42];
	char	*res;
	int		read_num;

	res = (char *)malloc(sizeof(char) * 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	while (1)
	{
		read_num = read(fd, buf, 10);
		if (read_num < 0)
		{
			if (res)
				free(res);
			return (NULL);
		}
		else if (read_num == 0)
			break ;
		buf[read_num] = '\0';
		res = ft_strjoin(res, buf);
		if (!res)
			return (NULL);
	}
	return (res);
}

char	*make_map_str(char *map_name)
{
	char	*res;
	int		fd;

	fd = open(map_name, O_RDONLY);
	res = read_map(fd);
	if (!res)
		exit_with_error("Map read failed");
	return (res);
}

void	map_check(t_sl *sl, char *map_name)
{
	char	*map_str;
	
	if (!check_map_name(map_name))
		exit_with_error("Map name must end with .cub");
	map_str = make_map_str(map_name);
	if (!map_str)
		exit_with_error("Map read failed");
	if (!map_str_check(sl, map_str))
	{
		free(map_str);
		exit(1);
	}
	printf("맵 크기: %d x %d\n", sl->mapinfo.x, sl->mapinfo.y);
	if (!map_make(sl, map_str))
	{
		free(map_str);
		exit(1);
	}
	free(map_str);
}
