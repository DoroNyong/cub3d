#include "../cub3d.h"

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && \
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && \
			line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

static char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

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

static void	parse_color(int *color, char *line)
{
	char	**rgb_values;
	t_rgb	colors;
	int		i;

	rgb_values = ft_split(line, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || \
		!rgb_values[2] || rgb_values[3])
	{
		printf("Error\n%s\n", "Invalid RGB color format.");
		exit(1);
	}
	colors.r = ft_atoi(rgb_values[0]);
	colors.g = ft_atoi(rgb_values[1]);
	colors.b = ft_atoi(rgb_values[2]);
	i = 0;
	while (rgb_values[i])
		free(rgb_values[i++]);
	free(rgb_values);
	if (colors.r < 0 || colors.r > 255 || colors.g < 0 || colors.g > 255 || \
		colors.b < 0 || colors.b > 255)
	{
		printf("Error\n%s\n", "RGB values must be between 0 and 255.");
		exit(1);
	}
	*color = (colors.r << 16) + (colors.g << 8) + colors.b;
}

void	parse_config_lines(t_sl *sl, char **lines)
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
		else if (ft_strncmp(line, "F ", 2) == 0)
			parse_color(&sl->config.F_color, line + 2);
		else if (ft_strncmp(line, "C ", 2) == 0)
			parse_color(&sl->config.C_color, line + 2);
		else if (*line != '\0' && !is_map_line(line))
		{
			printf("Error\n%s\n", "Invalid identifier in .cub file.");
			exit(1);
		}
		i++;
	}
}
