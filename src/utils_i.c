/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:29:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/02 22:07:39 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_matrix(t_game *cub)
{
	int			i;
	const int	fd = open(cub->map_path, O_RDONLY);

	i = -1;
	get_size(cub);
	cub->map_matrix = ft_calloc(cub->map.y, sizeof(char *));
	while (++i < cub->map.y)
		cub->map_matrix[i] = get_next_line(fd);
	get_next_line(fd);
	close(fd);
}

void	get_size(t_game *cub)
{
	int		fd;
	char	*string;

	fd = open(cub->map_path, O_RDONLY);
	string = get_next_line(fd);
	cub->map.x = 0;
	cub->map.y = 0;
	while (string)
	{
		if ((int)ft_strlen(string) > cub->map.x)
			cub->map.x = ft_strlen(string);
		cub->map.y++;
		free(string);
		string = get_next_line(fd);
	}
	free(string);
	close(fd);
}

t_coord	coordinate(double x, double y)
{
	t_coord	coordinate;

	coordinate.x = x;
	coordinate.y = y;
	return (coordinate);
}

t_vector	vector(double x, double y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
