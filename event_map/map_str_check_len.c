#include "../cub3d.h"

static void	update_map_info(t_sl *sl, int x)
{
	if (x > 0)
	{
		if (x > sl->mapinfo.x)
			sl->mapinfo.x = x;
		sl->mapinfo.y++;
	}
}

static void	process_map_line(t_sl *sl, char *map_str, int *index, int *x)
{
	while (map_str[*index] != '\0')
	{
		if (map_str[*index] == '\n')
		{
			if (*x > 0)
			{
				if (*x > sl->mapinfo.x)
					sl->mapinfo.x = *x;
			}
			sl->mapinfo.y++;
			*x = 0;
		}
		else
		{
			(*x)++;
		}
		(*index)++;
	}
}

void	map_len(t_sl *sl, char *map_str)
{
	int	index;
	int	x;

	index = 0;
	x = 0;
	process_map_line(sl, map_str, &index, &x);
	update_map_info(sl, x);
}
