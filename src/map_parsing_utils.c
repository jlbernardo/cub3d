#include "cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\n'
		|| c == '\f')
		return (1);
	return (0);
}

int ft_blank_line(char *line)
{
	while(*line && ft_isspace(*line))
		line++;
	if(*line)
		return (0);
	return (1);
}

int count_rows(int fd)
{
	int rows;
	char *temp_line;

	rows = 0;
	temp_line = get_next_line(fd);
	while(temp_line)
	{
		rows++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	return (rows);
}

int parsing_suite(t_game *cub)
{
	if (!get_texture_path(cub) || !get_colors(cub)
	|| !get_map(cub) || !get_player_direction(cub))
		return (false);
	return (true);
}