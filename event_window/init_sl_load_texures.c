#include "../cub3d.h"

static void	texture0(t_sl *sl)
{
	sl->texture[0].img = mlx_xpm_file_to_image(
			sl->data.mlx,
			sl->config.NO_path,
			&(sl->texture[0].width),
			&(sl->texture[0].height));
	sl->texture[0].addr = mlx_get_data_addr(
			sl->texture[0].img,
			&sl->texture[0].bits_per_pixel,
			&sl->texture[0].line_length,
			&sl->texture[0].endian);
}

static void	texture1(t_sl *sl)
{
	sl->texture[1].img = mlx_xpm_file_to_image(
			sl->data.mlx,
			sl->config.SO_path,
			&(sl->texture[1].width),
			&(sl->texture[1].height));
	sl->texture[1].addr = mlx_get_data_addr(
			sl->texture[1].img,
			&sl->texture[1].bits_per_pixel,
			&sl->texture[1].line_length,
			&sl->texture[1].endian);
}

static void	texture2(t_sl *sl)
{
	sl->texture[2].img = mlx_xpm_file_to_image(
			sl->data.mlx,
			sl->config.WE_path,
			&(sl->texture[2].width),
			&(sl->texture[2].height));
	sl->texture[2].addr = mlx_get_data_addr(
			sl->texture[2].img,
			&sl->texture[2].bits_per_pixel,
			&sl->texture[2].line_length,
			&sl->texture[2].endian);
}

static void	texture3(t_sl *sl)
{
	sl->texture[3].img = mlx_xpm_file_to_image(
			sl->data.mlx,
			sl->config.EA_path,
			&(sl->texture[3].width),
			&(sl->texture[3].height));
	sl->texture[3].addr = mlx_get_data_addr(
			sl->texture[3].img,
			&sl->texture[3].bits_per_pixel,
			&sl->texture[3].line_length,
			&sl->texture[3].endian);
}

void	load_texures(t_sl *sl)
{
	texture0(sl);
	texture1(sl);
	texture2(sl);
	texture3(sl);
}
