#include "../cub3d.h"

static void	no_check(t_sl *sl)
{
	int		fd;
	char	*file;

	file = sl->config.NO_path;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n'NO' texture file error.\n");
		free(sl->config.NO_path);
		exit(1);
	}
	else
		close(fd);
}

static void	so_check(t_sl *sl)
{
	int		fd;
	char	*file;

	file = sl->config.SO_path;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n'SO' texture file error.\n");
		free(sl->config.SO_path);
		exit(1);
	}
	else
		close(fd);
}

static void	we_check(t_sl *sl)
{
	int		fd;
	char	*file;

	file = sl->config.WE_path;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n'WE' texture file error.\n");
		free(sl->config.WE_path);
		exit(1);
	}
	else
		close(fd);
}

static void	ea_check(t_sl *sl)
{
	int		fd;
	char	*file;

	file = sl->config.EA_path;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n'EA' texture file error.\n");
		free(sl->config.EA_path);
		exit(1);
	}
	else
		close(fd);
}

void	check_tex(t_sl *sl)
{
	no_check(sl);
	so_check(sl);
	we_check(sl);
	ea_check(sl);
}
