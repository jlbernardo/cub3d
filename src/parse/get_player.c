/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:04 by julberna          #+#    #+#             */
/*   Updated: 2024/04/12 20:05:16 by julberna         ###   ########.fr       */
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
		while ((cub->map_matrix[i][j] && ft_isdigit(cub->map_matrix[i][j]))
			|| (cub->map_matrix[i][j] && is_space(cub->map_matrix[i][j])))
			j++;
		if (cub->map_matrix[i][j] && ft_isalpha(cub->map_matrix[i][j]))
		{
			if (cub->map_matrix[i][j] == 'N')
				cub->p1_start_direction = NO;
			else if (cub->map_matrix[i][j] == 'E')
				cub->p1_start_direction = EA;
			else if (cub->map_matrix[i][j] == 'S')
				cub->p1_start_direction = SO;
			else if (cub->map_matrix[i][j] == 'W')
				cub->p1_start_direction = WE;
			cub->p1 = coordinate(j, i);
			return ;
		}
	}
	cuberror("Player information not found.", cub);
}
