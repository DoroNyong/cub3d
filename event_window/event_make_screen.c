#include "../cub3d.h"

static void	preprocessing(t_sl *sl, int x)
{
	sl->draw.camera_x = 2 * x / (double)sl->data.screen_width - 1;
	sl->draw.ray_dir_x = sl->playerinfo.dir_x + \
						sl->playerinfo.plane_x * sl->draw.camera_x;
	sl->draw.ray_dir_y = sl->playerinfo.dir_y + \
						sl->playerinfo.plane_y * sl->draw.camera_x;
	sl->draw.map_x = (int)sl->playerinfo.pos_x;
	sl->draw.map_y = (int)sl->playerinfo.pos_y;
	if (sl->draw.ray_dir_x == 0)
		sl->draw.delta_dist_x = 1e30;
	else
		sl->draw.delta_dist_x = fabs(1 / sl->draw.ray_dir_x);
	if (sl->draw.ray_dir_y == 0)
		sl->draw.delta_dist_y = 1e30;
	else
		sl->draw.delta_dist_y = fabs(1 / sl->draw.ray_dir_y);
	sl->draw.hit = 0;
}

static void	ray_dir(t_sl *sl)
{
	if (sl->draw.ray_dir_x < 0)
	{
		sl->draw.step_x = -1;
		sl->draw.side_dist_x = (sl->playerinfo.pos_x - sl->draw.map_x) * \
								sl->draw.delta_dist_x;
	}
	else
	{
		sl->draw.step_x = 1;
		sl->draw.side_dist_x = (sl->draw.map_x + 1.0 - sl->playerinfo.pos_x) * \
								sl->draw.delta_dist_x;
	}
	if (sl->draw.ray_dir_y < 0)
	{
		sl->draw.step_y = -1;
		sl->draw.side_dist_y = (sl->playerinfo.pos_y - sl->draw.map_y) * \
								sl->draw.delta_dist_y;
	}
	else
	{
		sl->draw.step_y = 1;
		sl->draw.side_dist_y = (sl->draw.map_y + 1.0 - sl->playerinfo.pos_y) * \
								sl->draw.delta_dist_y;
	}
}

static void	draw_hit(t_sl *sl)
{
	while (sl->draw.hit == 0)
	{
		if (sl->draw.side_dist_x < sl->draw.side_dist_y)
		{
			sl->draw.side_dist_x += sl->draw.delta_dist_x;
			sl->draw.map_x += sl->draw.step_x;
			sl->draw.side = 0;
		}
		else
		{
			sl->draw.side_dist_y += sl->draw.delta_dist_y;
			sl->draw.map_y += sl->draw.step_y;
			sl->draw.side = 1;
		}
		if (sl->map[sl->draw.map_x][sl->draw.map_y] == '1')
			sl->draw.hit = 1;
	}
}

static void	distance(t_sl *sl)
{
	if (sl->draw.side == 0)
		sl->draw.perp_wall_dist = (sl->draw.map_x - sl->playerinfo.pos_x \
			+ (1 - sl->draw.step_x) / 2) / sl->draw.ray_dir_x;
	else
		sl->draw.perp_wall_dist = (sl->draw.map_y - sl->playerinfo.pos_y \
			+ (1 - sl->draw.step_y) / 2) / sl->draw.ray_dir_y;
	sl->draw.line_height = (int)(sl->data.screen_height / \
							sl->draw.perp_wall_dist);
	sl->draw.start = -sl->draw.line_height / 2 + sl->data.screen_height / 2;
	if (sl->draw.start < 0)
		sl->draw.start = 0;
	sl->draw.end = sl->draw.line_height / 2 + sl->data.screen_height / 2;
	if (sl->draw.end >= sl->data.screen_height)
		sl->draw.end = sl->data.screen_height - 1;
}

void	make_screen(t_sl *sl)
{
	int	x;

	x = 0;
	while (x < sl->data.screen_width)
	{
		preprocessing(sl, x);
		ray_dir(sl);
		draw_hit(sl);
		distance(sl);
		draw_texture(sl, x);
		x++;
	}
	mlx_put_image_to_window(sl->data.mlx, sl->data.win, sl->pixel.img, 0, 0);
}
