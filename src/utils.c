/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:29:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/12 15:33:32 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	not_on_minimap(t_game *cub, t_coord start)
{
	if (start.y < cub->minimap->instances->x
		|| start.y > cub->mini_size.x
		|| start.x < cub->minimap->instances->y
		|| start.x > cub->mini_size.y)
		return (true);
	return (false);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][0])
		{
			free(matrix[i]);
			matrix[i] = NULL;
		}
		i++;
	}
	if (matrix)
	{
		free(matrix);
		matrix = NULL;
	}
}
