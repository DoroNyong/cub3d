/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:26:47 by hjang             #+#    #+#             */
/*   Updated: 2025/10/08 17:27:59 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (argc != 2)
	{
		if (argc == 1)
			printf("Error\nMap not found.\n");
		else
			printf("Error\nOnly one map allowed.\n");
		return (0);
	}
	map_init(&sl);
	map_check(&sl, argv[1]);
	sl_init(&sl);
	mlx_hook(sl.data.win, 2, 1L << 0, &key_press, &sl);
	mlx_hook(sl.data.win, 3, 1L << 1, &key_release, &sl);
	mlx_hook(sl.data.win, 17, 0, &close_window, &sl);
	mlx_loop_hook(sl.data.mlx, &game_loop, &sl);
	mlx_loop(sl.data.mlx);
	return (0);
}
