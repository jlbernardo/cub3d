/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:02:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/21 19:56:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validation(t_game *cub)
{
	check_extension(cub);
	check_keys(cub);
	check_walls(cub, cub->p1);
}

void	check_extension(t_game *cub)
{
	int	lenght;

	lenght = ft_strlen(cub->map_path);
	if (lenght < 4 || ft_strcmp((cub->map_path + (lenght - 4)), ".cub"))
		cuberror("Wrong file extension.", cub);
}

void	check_keys(t_game *cub)
{
	int		i;
	int		j;
	bool	player_found;

	i = -1;
	player_found = false;
	while (cub->map_matrix[++i])
	{
		j = -1;
		while (cub->map_matrix[i][++j])
		{
			if (!ft_strchr(" 0123NSEW", cub->map_matrix[i][j]))
				cuberror("Found unrecognized characters on the map.", cub);
			if (ft_strchr("NSEW", cub->map_matrix[i][j]))
			{
				if (player_found)
					cuberror("More than one player found.", cub);
				player_found = true;
			}
		}
	}
}
