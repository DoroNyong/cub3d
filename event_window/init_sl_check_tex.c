#include "../cub3d.h"

static void	check_texture_file(char *path)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error\nTexture file must have .xpm extension: %s\n", path);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open texture file: %s\n", path);
		exit(1);
	}
	close(fd);
}

static void	check_texdir(char **paths, int count)
{
	int	i;

	if (count == 0)
		return ;
	i = 0;
	while (i < count)
	{
		check_texture_file(paths[i]);
		i++;
	}
}

void	check_tex(t_sl *sl)
{
	check_texdir(sl->config.no_path, sl->config.no_count);
	check_texdir(sl->config.so_path, sl->config.so_count);
	check_texdir(sl->config.we_path, sl->config.we_count);
	check_texdir(sl->config.ea_path, sl->config.ea_count);
}
