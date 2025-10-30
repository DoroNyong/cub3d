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
	if (sl->config.no_count == 0)
		handle_error("no_path is missing.");
	if (sl->config.so_count == 0)
		handle_error("so_path is missing.");
	if (sl->config.we_count == 0)
		handle_error("we_path is missing.");
	if (sl->config.ea_count == 0)
		handle_error("ea_path is missing.");
	if (sl->config.f_color == -1)
		handle_error("f_color is missing.");
	if (sl->config.c_color == -1)
		handle_error("c_color is missing.");
}

void	parse_config_lines(t_sl *sl, char **lines)
{
	parsing_texture(sl, lines);
	parsing_colors(sl, lines);
	checking_parsing(sl);
}
