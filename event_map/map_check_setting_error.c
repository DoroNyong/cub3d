/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_check_setting_error.c						  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: byeolee <byeolee@student.42gyeongsan.kr	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/11/05 16:46:12 by byeolee		   #+#	#+#			 */
/*   Updated: 2025/11/29 13:56:03 by byeolee		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../cub3d.h"

static void	checking_parsing(t_sl *sl, char **lines)
{
	if (sl->config.no_count == 0)
		handle_error(sl, lines, "no_path is missing.");
	if (sl->config.so_count == 0)
		handle_error(sl, lines, "so_path is missing.");
	if (sl->config.we_count == 0)
		handle_error(sl, lines, "we_path is missing.");
	if (sl->config.ea_count == 0)
		handle_error(sl, lines, "ea_path is missing.");
	if (sl->config.f_count != 1)
		handle_error(sl, lines, "Enter floor color less or more than one.");
	if (sl->config.c_count != 1)
		handle_error(sl, lines, "Enter ceiling color less or more than one.");
	if (sl->config.f_color == -1)
		handle_error(sl, lines, "f_color is missing.");
	if (sl->config.c_color == -1)
		handle_error(sl, lines, "c_color is missing.");
}

static int	check_setting_exist(t_sl *sl)
{
	if (sl->config.no_count == 0 || sl->config.so_count == 0 || \
		sl->config.we_count == 0 || sl->config.ea_count == 0 || \
		sl->config.f_count == 0 || sl->config.c_count == 0)
		return (0);
	return (1);
}

static int	check_settings_last(char **lines, int i)
{
	char	*line;

	while (lines[i])
	{
		line = skip_whitespace(lines[i]);
		if (!line)
		{
			i++;
			continue ;
		}
		if (ft_strncmp(line, "NO ", 3) == 0
			|| ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0
			|| ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_setting(t_sl *sl, char **lines, int i)
{
	if (!check_setting_exist(sl))
	{
		if (check_settings_last(lines, i))
			handle_error(sl, lines, "Map must be entered after setting value");
		else
			checking_parsing(sl, lines);
	}
	return (i);
}
