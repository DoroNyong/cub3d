#include "../cub3d.h"

int	close_window(t_sl *sl)
{
	mlx_mouse_show(sl->data.mlx, sl->data.win);
	mlx_destroy_image(sl->data.mlx, sl->texture[0].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[1].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[2].img);
	mlx_destroy_image(sl->data.mlx, sl->texture[3].img);
	mlx_destroy_image(sl->data.mlx, sl->pixel.img);
	mlx_destroy_window(sl->data.mlx, sl->data.win);
	mlx_destroy_display(sl->data.mlx);
	free(sl->data.mlx);
	free_map(sl, sl->mapinfo.x);
	if (sl->config.NO_path)
		free(sl->config.NO_path);
	if (sl->config.SO_path)
		free(sl->config.SO_path);
	if (sl->config.WE_path)
		free(sl->config.WE_path);
	if (sl->config.EA_path)
		free(sl->config.EA_path);
	exit(0);
	return (0);
}
