/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:36 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/14 20:17:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(t_game *cub, int argc, char **argv)
{
	check_input(cub, argc, argv);
	get_texture_path(cub);
	get_colors(cub);
	get_map(cub);
	get_player_direction(cub);
}

void	check_input(t_game *cub, int argc, char **argv)
{
	ft_bzero(cub, sizeof(t_game));
	if (argc != 2)
		cuberror("Wrong number of arguments.", cub);
	cub->map_path = argv[1];
	cub->map_data.raw_data = get_raw_data(cub->map_path, cub);
}

char	**get_raw_data(char *map_path, t_game *cub)
{
	int		i;
	int		fd;
	int		rows;
	char	*temp_line;
	char	**raw_data;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		cuberror("Could not open map file.", cub);
	rows = count_rows(fd);
	close(fd);
	fd = open(map_path, O_RDONLY);
	raw_data = (char **)ft_calloc(rows + 1, sizeof(char *));
	while (i < rows)
	{
		temp_line = get_next_line(fd);
		raw_data[i] = (char *)ft_calloc(ft_strlen(temp_line) + 1, sizeof(char));
		if (raw_data[i] && temp_line)
			ft_strlcpy(raw_data[i], temp_line, ft_strlen(temp_line) + 1);
		i++;
		free(temp_line);
	}
	return (raw_data);
}

int	count_rows(int fd)
{
	int		rows;
	char	*temp_line;

	rows = 0;
	temp_line = get_next_line(fd);
	while (temp_line)
	{
		rows++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	return (rows);
}
