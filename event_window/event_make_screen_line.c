#include "../cub3d.h"

void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_length \
			+ x * (pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_background_line(t_sl *sl, int x)
{
	int	index;

	index = 0;
	while (index < sl->draw.start)
	{
		my_mlx_pixel_put(&sl->pixel, x, index, 0x000080);
		index++;
	}
}

static void	draw_texture_line(t_sl *sl, int x)
{
	sl->draw.step = 1.0 * sl->texture[sl->draw.tex_dir].height \
		/ sl->draw.line_height;
	sl->draw.tex_pos = (sl->draw.start - sl->data.screen_height \
		/ 2 + sl->draw.line_height / 2) * sl->draw.step;
	while (sl->draw.start <= sl->draw.end - 1)
	{
		sl->draw.tex_y = (int)sl->draw.tex_pos \
			% sl->texture[sl->draw.tex_dir].height;
		sl->draw.tex_pos += sl->draw.step;
		sl->draw.tex_pixel = sl->texture[sl->draw.tex_dir].addr \
			+ (sl->draw.tex_y \
			* sl->texture[sl->draw.tex_dir].line_length \
			+ sl->draw.tex_x \
			* (sl->texture[sl->draw.tex_dir].bits_per_pixel / 8));
		sl->draw.color = *(unsigned int *)sl->draw.tex_pixel;
		my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->draw.color);
		sl->draw.start++;
	}
	my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, sl->draw.color);
	sl->draw.start++;
}

static void	draw_bottom_line(t_sl *sl, int x)
{
	while (sl->draw.start <= sl->data.screen_height)
	{
		my_mlx_pixel_put(&sl->pixel, x, sl->draw.start, 0x8B0000);
		sl->draw.start++;
	}
}

void	draw_vertical_line(t_sl *sl, int x)
{
	draw_background_line(sl, x);
	draw_texture_line(sl, x);
	draw_bottom_line(sl, x);
}
