/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:32:17 by hjang             #+#    #+#             */
/*   Updated: 2025/10/30 18:25:10 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	game_loop(t_sl *sl)
{
	int	pressed;

	sl->anim.frame_count++;
	if (sl->anim.frame_count > 75)
	{
		sl->anim.corrent_frame++;
		if (sl->anim.corrent_frame > 2)
			sl->anim.corrent_frame = 0;
		sl->anim.frame_count = 0;
	}
	pressed = sl->keys.w + sl->keys.a + sl->keys.s + sl->keys.d;
	if (pressed == 2)
		sl->playerinfo.diag_speed = 1.0 / sqrt(2);
	else
		sl->playerinfo.diag_speed = 1.0;
	mouse_rotate(sl);
	key_move(sl);
	sl->anim.frame_counter++;
	if (sl->anim.frame_counter >= sl->anim.frame_delay)
	{
		sl->anim.frame_counter = 0;
		sl->anim.corrent_frame++;
	}
	make_screen(sl);
	return (0);
}
