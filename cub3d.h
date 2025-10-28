/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:27:06 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 02:03:55 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/time.h>
# include <math.h>

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		screen_width;
	int		screen_height;
}	t_data;

typedef struct s_pixel {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_pixel;

typedef struct s_mapinfo
{
	int	x;
	int	y;
	int	player_exists;
}	t_mapinfo;

typedef struct s_playerinfo
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	diag_speed;
}	t_playerinfo;


typedef enum e_tex_dir{
	N,
	S,
	W,
	E
}	t_tex_dir;

typedef struct s_draw
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			start;
	int			end;
	int			color;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
	char		*tex_pixel;
	t_tex_dir	tex_dir;
}	t_draw;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}	t_keys;

typedef struct s_mouse
{
	int	prev_x;
	int	smooth_dx;
}	t_mouse;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_minimap
{
	double	fov;
	int		num_rays;
	double	ray_step;
	double	max_ray_dist;
	int		minimap_scale;
}	t_minimap;

typedef struct s_anim
{
	int	frame_count;
	int	corrent_frame;
}	t_anim;

typedef struct s_sl
{
	t_data			data;
	t_pixel			pixel;
	t_mapinfo		mapinfo;
	t_playerinfo	playerinfo;
	t_draw			draw;
	t_keys			keys;
	t_mouse			mouse;
	t_texture		texture[12];
	t_minimap		minimap;
	t_anim			anim;
	char			**map;
}	t_sl;

void	map_init(t_sl *sl);
void	sl_init(t_sl *sl);
int		key_press(int keycode, t_sl *sl);
int		mouse_press(int button, int x, int y, void *p);
void	map_check(t_sl *sl, char *map_name);
int		map_str_check(t_sl *sl, char *map_name);
int		map_make(t_sl *sl, char *map_str);
int		map_wall_check(t_sl *sl);
void	free_map(t_sl *sl, int index);
int		close_window(t_sl *sl);
int		key_press(int keycode, t_sl *sl);
int		key_release(int keycode, t_sl *sl);
void	key_move_w(t_sl *sl);
void	key_move_a(t_sl *sl);
void	key_move_s(t_sl *sl);
void	key_move_d(t_sl *sl);
void	key_rotate_left(t_sl *sl);
void	key_rotate_right(t_sl *sl);
void	make_screen(t_sl *sl);
int		game_loop(t_sl *sl);
void	mouse_rotate(t_sl *sl);
void	draw_minimap(t_sl *sl);
void	my_mlx_pixel_put(t_pixel *pixel, int x, int y, int color);

#endif