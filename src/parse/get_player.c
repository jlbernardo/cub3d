/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:04 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 21:13:50 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_direction(t_game *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map_matrix[++i])
	{
		j = 0;
		while (cub->map_matrix[i][j]
			&& (ft_isdigit(cub->map_matrix[i][j])
				|| is_space(cub->map_matrix[i][j])))
			j++;
		if (cub->map_matrix[i][j] && ft_isalpha(cub->map_matrix[i][j]))
		{
			set_direction(cub, i, j);
			return ;
		}
	}
	cuberror("Player information not found.", cub);
}

void	set_direction(t_game *cub, int i, int j)
{
	if (cub->map_matrix[i][j] == 'N')
	{
		cub->direction = vector(0, 1);
		cub->camera_plane = vector(0.66, 0);
	}
	else if (cub->map_matrix[i][j] == 'E')
	{
		cub->direction = vector(1, 0);
		cub->camera_plane = vector(0, -0.66);
	}
	else if (cub->map_matrix[i][j] == 'S')
	{
		cub->direction = vector(0, -1);
		cub->camera_plane = vector(-0.66, 0);
	}
	else if (cub->map_matrix[i][j] == 'W')
	{
		cub->direction = vector(-1, 0);
		cub->camera_plane = vector(0, 0.66);
	}
	else
		cuberror("Player direction not recognized.", cub);
	cub->p1 = coordinate(j, i);
}
