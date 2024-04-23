/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:29:32 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/04/22 21:02:48 by aperis-p         ###   ########.fr       */
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

void	copy_matrix(t_game *cub)
{
	int		i;
	char	*temp;

	i = -1;
	cub->map_data.copy = ft_calloc(cub->map.y + 1, sizeof(char *));
	while (++i < cub->map.y)
	{
		temp = ft_strdup(cub->map_matrix[i]);
		cub->map_data.copy[i] = ft_strjoin(temp, "\n");
		free(temp);
	}
	cub->map_data.copy[i] = NULL;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	if (matrix)
	{
		free(matrix);
		matrix = NULL;
	}
}

void	cuberror(char *message, t_game *cub)
{
	write(STDERR_FILENO, "\033[1;31mError!\033[0m\n", 18);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	over(cub, EXIT_FAILURE);
}
