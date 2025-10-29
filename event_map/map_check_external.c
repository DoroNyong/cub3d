#include "../cub3d.h"

static int	check_map_name(char *map_name)
{
	int	len;

	len = 0;
	while (map_name[len])
		len++;
	if (len < 5)
		return (0);
	if (!(map_name[len - 1] == 'b' && map_name[len - 2] == 'u' \
		&& map_name[len - 3] == 'c' && map_name[len - 4] == '.'))
		return (0);
	if (!((map_name[len - 5] >= 'a' && map_name[len - 5] <= 'z') \
		|| (map_name[len - 5] >= 'A' && map_name[len - 5] <= 'Z') \
		|| (map_name[len - 5] >= '0' && map_name[len - 5] <= '9')))
		return (0);
	return (1);
}

static char	*append_to_result(char *res, char *buf)
{
	char	*temp;

	temp = res;
	res = ft_strjoin(res, buf);
	if (!res)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (res);
}

static char	*read_map(int fd)
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
		res = append_to_result(res, buf);
		if (!res)
			return (NULL);
	}
	return (res);
}

static char	*make_map_str(char *map_name)
{
	char	*res;
	int		fd;

	fd = open(map_name, O_RDONLY);
	res = read_map(fd);
	if (!res)
	{
		printf("Error\n%s\n", "Map read failed");
		exit(1);
	}
	return (res);
}

void	map_exception(char *map_name, char **full_file, char ***lines)
{
	if (!check_map_name(map_name))
	{
		printf("Error\n%s\n", "Map name must end with .cub");
		exit(1);
	}
	*full_file = make_map_str(map_name);
	if (!*full_file)
	{
		printf("Error\n%s\n", "Map read failed");
		exit(1);
	}
	*lines = ft_split(*full_file, '\n');
	if (!*lines)
	{
		printf("Error\n%s\n", "Map read lines failed");
		exit(1);
	}
}
