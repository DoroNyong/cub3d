/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:26:47 by hjang             #+#    #+#             */
/*   Updated: 2025/09/26 17:20:16 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (argc != 2)
	{
		printf("Error\n반드시 하나의 맵을 사용해야 합니다.\n");
		return (0);
	}
	map_init(&sl);
	map_check(&sl, argv[1]);
	sl_init(&sl);
	mlx_hook(sl.data.win, 2, 1L<<0, &key_press, &sl);
	mlx_hook(sl.data.win, 3, 1L<<1, &key_release, &sl);
	mlx_hook(sl.data.win, 17, 0, &close_window, &sl);
	mlx_loop_hook(sl.data.mlx, &game_loop, &sl);
	mlx_loop(sl.data.mlx);
	return (0);
}
