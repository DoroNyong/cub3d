#include "../cub3d.h"

static void	parse_texture(char **texture_path, char *line)
{
	if (*texture_path != NULL)
		free(*texture_path);
	*texture_path = ft_strtrim(line, " \t");
	if (!*texture_path)
	{
		printf("Error\n%s\n", "Failed to allocate memory for texture path.");
		exit(1);
	}
}

void	parsing_texture(t_sl *sl, char **lines)
{
	int		i;
	char	*line;

	i = 0;
	while (lines[i])
	{
		line = skip_whitespace(lines[i]);
		if (ft_strncmp(line, "NO ", 3) == 0)
			parse_texture(&sl->config.NO_path, line + 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_texture(&sl->config.SO_path, line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_texture(&sl->config.WE_path, line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_texture(&sl->config.EA_path, line + 3);
		i++;
	}
}
