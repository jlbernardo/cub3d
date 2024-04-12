/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:28:36 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/12 16:37:24 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

char	**get_raw_data(char *map_path)
{
	int		i;
	int		fd;
	int		rows;
	char	*temp_line;
	char	**raw_data;

	i = 0;
	fd = open(map_path, O_RDONLY);
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

// void	ft_print_matrix(char **matrix) // DELETE ME BEFORE SEND TO VOGSPHERE!
// {
// 	while (*matrix)
// 	{
// 		ft_printf("%s", *matrix);
// 		matrix++;
// 	}
// }
