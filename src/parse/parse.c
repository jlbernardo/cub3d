/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:15:02 by julberna          #+#    #+#             */
/*   Updated: 2024/04/14 20:13:52 by julberna         ###   ########.fr       */
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
	get_raw_data(cub->map_path, cub);
}

void	get_raw_data(char *map_path, t_game *cub)
{
	int		i;
	int		fd;
	int		rows;
	char	*temp_line;

	i = 0;
	rows = count_rows(cub, map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		cuberror("Could not open map file. ☹", cub);
	cub->map_data.raw_data = (char **)ft_calloc(rows + 1, sizeof(char *));
	temp_line = get_next_line(fd);
	while (temp_line)
	{
		cub->map_data.raw_data[i] = ft_strdup(temp_line);
		free(temp_line);
		temp_line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	count_rows(t_game *cub, char *map_path)
{
	int		fd;
	int		rows;
	char	*temp_line;

	rows = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		cuberror("Could not open map file. ( ｡ • ᴖ •｡)", cub);
	temp_line = get_next_line(fd);
	while (temp_line)
	{
		rows++;
		free(temp_line);
		temp_line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}
