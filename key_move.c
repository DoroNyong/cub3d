/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:42:31 by hjang             #+#    #+#             */
/*   Updated: 2025/09/24 06:37:14 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_move_w(t_sl *sl)
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
	printf("player_pos %f, %f / player_speed = %f\n", sl->playerinfo.pos_x, sl->playerinfo.pos_y, sl->playerinfo.move_speed * sl->playerinfo.diag_speed);
}

void	key_move_a(t_sl *sl)
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
	printf("player_pos %f, %f / player_speed = %f\n", sl->playerinfo.pos_x, sl->playerinfo.pos_y, sl->playerinfo.move_speed * sl->playerinfo.diag_speed);
}

void	key_move_s(t_sl *sl)
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
	printf("player_pos %f, %f / player_speed = %f\n", sl->playerinfo.pos_x, sl->playerinfo.pos_y, sl->playerinfo.move_speed * sl->playerinfo.diag_speed);
}

void	key_move_d(t_sl *sl)
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
	printf("player_pos %f, %f / player_speed = %f\n", sl->playerinfo.pos_x, sl->playerinfo.pos_y, sl->playerinfo.move_speed * sl->playerinfo.diag_speed);
}
