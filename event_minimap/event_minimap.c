/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:32:57 by hjang             #+#    #+#             */
/*   Updated: 2025/10/29 17:02:16 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	draw_minimap(t_sl *sl)
{
	draw_minimap_map(sl);
	draw_minimap_cha(sl);
	draw_minimap_fov(sl);
}
