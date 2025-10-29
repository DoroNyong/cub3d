#include "../cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

static void	handle_error(const char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

static void	checking_parsing(t_sl *sl)
{
	if (sl->config.NO_path == NULL)
		handle_error("NO_path is missing.");
	if (sl->config.SO_path == NULL)
		handle_error("SO_path is missing.");
	if (sl->config.WE_path == NULL)
		handle_error("WE_path is missing.");
	if (sl->config.EA_path == NULL)
		handle_error("EA_path is missing.");
	if (sl->config.F_color == -1)
		handle_error("F_color is missing.");
	if (sl->config.C_color == -1)
		handle_error("C_color is missing.");
}

void	parse_config_lines(t_sl *sl, char **lines)
{
	parsing_texture(sl, lines);
	parsing_colors(sl, lines);
	checking_parsing(sl);
}
