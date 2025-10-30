#include "../cub3d.h"

static int	load_single_texture(t_sl *sl, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(sl->data.mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error\nFailed to load texture: %s\n", path);
		return (-1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		printf("Error\nFailed to get texture data address for: %s\n", path);
		mlx_destroy_image(sl->data.mlx, texture->img);
		texture->img = NULL;
		return (-1);
	}
	return (0);
}

static void	load_pertex(t_sl *sl, char **paths, int count, int *tex_idx)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (load_single_texture(sl, &sl->textures[*tex_idx], paths[i]) != 0)
			exit(1);
		(*tex_idx)++;
		i++;
	}
}

void	load_tex(t_sl *sl)
{
	int	tex_index;

	sl->total_tex_count = sl->config.no_count + sl->config.so_count
		+ sl->config.we_count + sl->config.ea_count;
	if (sl->total_tex_count == 0)
	{
		sl->textures = NULL;
		return ;
	}
	sl->tex_counts[N] = sl->config.no_count;
	sl->tex_counts[S] = sl->config.so_count;
	sl->tex_counts[W] = sl->config.we_count;
	sl->tex_counts[E] = sl->config.ea_count;
	sl->tex_offsets[N] = 0;
	sl->tex_offsets[S] = sl->config.no_count;
	sl->tex_offsets[W] = sl->config.no_count + sl->config.so_count;
	sl->tex_offsets[E] = sl->config.no_count + sl->config.so_count + sl->config.we_count;
	sl->textures = (t_texture *)malloc(sizeof(t_texture) * sl->total_tex_count);
	if (!sl->textures)
	{
		printf("Error\nFailed to allocate memory for textures.\n");
		exit(1);
	}
	tex_index = 0;
	load_pertex(sl, sl->config.no_path, sl->config.no_count, &tex_index);
	load_pertex(sl, sl->config.so_path, sl->config.so_count, &tex_index);
	load_pertex(sl, sl->config.we_path, sl->config.we_count, &tex_index);
	load_pertex(sl, sl->config.ea_path, sl->config.ea_count, &tex_index);
}
