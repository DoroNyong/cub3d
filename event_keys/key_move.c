/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:42:31 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 17:21:59 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	key_move_w(t_sl *sl)
{		
	if (sl->map[(int)(sl->playerinfo.pos_x + sl->playerinfo.dir_x \
		* sl->playerinfo.move_speed * sl->playerinfo.diag_speed)] \
		[(int)(sl->playerinfo.pos_y)] != '1')
		sl->playerinfo.pos_x += sl->playerinfo.dir_x \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
	if (sl->map[(int)(sl->playerinfo.pos_x)][(int)(sl->playerinfo.pos_y \
		+ sl->playerinfo.dir_y * sl->playerinfo.move_speed \
		* sl->playerinfo.diag_speed)] != '1')
		sl->playerinfo.pos_y += sl->playerinfo.dir_y \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
}

static void	key_move_a(t_sl *sl)
{
	if (sl->map[(int)(sl->playerinfo.pos_x - sl->playerinfo.plane_x \
		* sl->playerinfo.move_speed * sl->playerinfo.diag_speed)] \
		[(int)(sl->playerinfo.pos_y)] != '1')
		sl->playerinfo.pos_x -= sl->playerinfo.plane_x \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
	if (sl->map[(int)(sl->playerinfo.pos_x)][(int)(sl->playerinfo.pos_y \
		- sl->playerinfo.plane_y * sl->playerinfo.move_speed \
		* sl->playerinfo.diag_speed)] != '1')
		sl->playerinfo.pos_y -= sl->playerinfo.plane_y \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
}

static void	key_move_s(t_sl *sl)
{
	if (sl->map[(int)(sl->playerinfo.pos_x - sl->playerinfo.dir_x \
		* sl->playerinfo.move_speed * sl->playerinfo.diag_speed)] \
		[(int)(sl->playerinfo.pos_y)] != '1')
		sl->playerinfo.pos_x -= sl->playerinfo.dir_x \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
	if (sl->map[(int)(sl->playerinfo.pos_x)][(int)(sl->playerinfo.pos_y \
		- sl->playerinfo.dir_y * sl->playerinfo.move_speed \
		* sl->playerinfo.diag_speed)] != '1')
		sl->playerinfo.pos_y -= sl->playerinfo.dir_y \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
}

static void	key_move_d(t_sl *sl)
{
	if (sl->map[(int)(sl->playerinfo.pos_x + sl->playerinfo.plane_x \
		* sl->playerinfo.move_speed * sl->playerinfo.diag_speed)] \
		[(int)(sl->playerinfo.pos_y)] != '1')
		sl->playerinfo.pos_x += sl->playerinfo.plane_x \
		* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
	if (sl->map[(int)(sl->playerinfo.pos_x)][(int)(sl->playerinfo.pos_y \
		+ sl->playerinfo.plane_y * sl->playerinfo.move_speed \
		* sl->playerinfo.diag_speed)] != '1')
		sl->playerinfo.pos_y += sl->playerinfo.plane_y \
			* sl->playerinfo.move_speed * sl->playerinfo.diag_speed;
}

void	key_move(t_sl *sl)
{
	if (sl->keys.w)
		key_move_w(sl);
	if (sl->keys.a)
		key_move_a(sl);
	if (sl->keys.s)
		key_move_s(sl);
	if (sl->keys.d)
		key_move_d(sl);
	if (sl->keys.left)
		key_rotate_left(sl);
	if (sl->keys.right)
		key_rotate_right(sl);
	if (sl->keys.esc)
		close_window(sl);
}
