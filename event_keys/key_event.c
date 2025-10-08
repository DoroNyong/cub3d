/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:38:19 by hjang             #+#    #+#             */
/*   Updated: 2025/10/06 13:08:20 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_sl *sl)
{
	if (keycode == KEY_W)
		sl->keys.w = 1;
	if (keycode == KEY_A)
		sl->keys.a = 1;
	if (keycode == KEY_S)
		sl->keys.s = 1;
	if (keycode == KEY_D)
		sl->keys.d = 1;
	if (keycode == KEY_LEFT)
		sl->keys.left = 1;
	if (keycode == KEY_RIGHT)
		sl->keys.right = 1;
	if (keycode == KEY_ESC)
		sl->keys.esc = 1;
	return (0);
}

int	key_release(int keycode, t_sl *sl)
{
	if (keycode == KEY_W)
		sl->keys.w = 0;
	if (keycode == KEY_A)
		sl->keys.a = 0;
	if (keycode == KEY_S)
		sl->keys.s = 0;
	if (keycode == KEY_D)
		sl->keys.d = 0;
	if (keycode == KEY_LEFT)
		sl->keys.left = 0;
	if (keycode == KEY_RIGHT)
		sl->keys.right = 0;
	if (keycode == KEY_ESC)
		sl->keys.esc = 0;
	return (0);
}
