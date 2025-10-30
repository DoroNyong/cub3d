#include "../cub3d.h"

int	close_window(t_sl *sl)
{
	mlx_mouse_show(sl->data.mlx, sl->data.win);
	mlx_destroy_image(sl->data.mlx, sl->pixel.img);
	mlx_destroy_window(sl->data.mlx, sl->data.win);
	mlx_destroy_display(sl->data.mlx);
	free(sl->data.mlx);
	free_map(sl, sl->mapinfo.x);
	if (sl->config.no_path)
		free(sl->config.no_path);
	if (sl->config.so_path)
		free(sl->config.so_path);
	if (sl->config.we_path)
		free(sl->config.we_path);
	if (sl->config.ea_path)
		free(sl->config.ea_path);
	exit(0);
	return (0);
}
